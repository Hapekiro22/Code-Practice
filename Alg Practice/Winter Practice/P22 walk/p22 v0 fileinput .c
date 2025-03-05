#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXBLOCK 10005
#define MAXNEIGHBOR 15

//定义单元格，包含颜色，坐标，剩余可选方向，单元格所属同色连通块颜色以及该色块的编码
typedef struct cell {
    int color;
    int x;
    int y;
    int direction[4];
    int block_code;
    int edge;                       //判断cell是否是所属block的边界
    struct cell *next, *prev;              //仅用于构造block时保证每次取到未分配的节点
} cell;

//规定色块是连通的同色单元格组成的集合，每个色块有一个唯一的编码
//定义同色连通块，包含颜色，编码，单元格数组，相邻的其它色块
typedef struct block{
    int color;
    int code;
    int *direction;
    cell *cells;
    struct block **neighbors;
} block;

//深度优先搜索，用于构造同色连通块
//构造过程中删除线性连接部分从而避免重复访问
void DFS(cell **Matrix, int m, cell *current, block *Block, int BlockCode, int *CellCount) 
{
    current->block_code = BlockCode;
    current->edge = 1;
    Block->cells[(*CellCount)++] = *current;    
    //删除线性连接
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    for (int i = 0; i < MAXNEIGHBOR; i++) {
        if (current->direction[i] == 1) {
            cell *next = NULL;
            switch (i) {
                case 0:
                    next = current - m;
                    break;
                case 1:
                    next = current + 1;
                    break;
                case 2:
                    next = current + m;
                    break;
                case 3:
                    next = current - 1;
                    break;
            }
            if (next != NULL && next->color == current->color && next->block_code == 0) {
                current->direction[i] = 0;
                next->direction[(i + 2) % 4] = 0;
                next->edge = 0;                                             //非边界
                DFS(Matrix, m, next, Block, BlockCode, CellCount);
            }
        }
    }
}

//创建单一色块，采用深度优先搜索即可
//从start开始，遍历所有相邻的同色cell，直到所有相邻同色cell都被遍历
//block的相邻块的指针数组初始化为NULL
//在搜索过程中，将四周都是同色的cell的edge属性设为0，其他设为1
block* CreateXBlocks(cell **Matrix,int m,cell *start,int BlockCode)
{
    cell *begin = start;
    block *Block = (block *)malloc(sizeof(block));
    Block -> color = begin -> color;
    Block -> code = BlockCode;
    Block -> direction = (int *)malloc(MAXNEIGHBOR*sizeof(int));
    Block -> cells = (cell *)malloc(MAXBLOCK*sizeof(cell));
    Block -> neighbors = (block **)malloc(MAXNEIGHBOR*sizeof(block *));
    for(int i = 0;i < MAXNEIGHBOR;i++)
        Block -> direction[i] = 0;
    int CellCount = 0;
    DFS(Matrix,m,begin,Block,BlockCode,&CellCount);

    return Block;

}

//函数CreateBlocks用于创建m*m矩阵中所有的色块，并返回一个色块数组
//要求传入的Matrix是全部完成初始化，并且所有 cell 的 block_code = 0 的矩阵
//矩阵的每一个节点同时还是线性连接的
block **CreateBlocks(cell **Matrix,int m)
{
    int BlockCount = 1;
    block **BlockGroup = (block **)malloc(MAXBLOCK*sizeof(block *));//构造链表的起点
    cell *start = (cell *)malloc(sizeof(cell));
    start -> next = NULL;
    start -> prev = NULL;
    //以start为空节点，将所有节点连接成一个链表
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < m;j++)
        {
                if(start->next == NULL)
                {
                    start->next = &Matrix[i][j];
                    Matrix[i][j].prev = start;
                    Matrix[i][j].next = NULL; // 确保最后一个节点的 next 为 NULL
                }
                else
                {
                    cell *last = start;
                    while(last->next != NULL)
                    {
                        last = last->next;
                    }
                    last->next = &Matrix[i][j];
                    Matrix[i][j].prev = last;
                    Matrix[i][j].next = NULL; // 确保最后一个节点的 next 为 NULL
        }
        }
    }

    while(start -> next != NULL)
    {
        *(BlockGroup + BlockCount - 1) = CreateXBlocks(Matrix,m,start -> next,BlockCount);
        BlockCount++;
    }

    return BlockGroup;
}

//函数GetBlockNeighbor用于获取一个色块的所有相邻色块
//只需要沿着色块的边界遍历即可
void GetBlockNeighbor(block **BlockGroup,int BLockCount,int m)
{
    for(int i = 0;i < BLockCount;i++)
    {
        for(int j = 0;j < MAXBLOCK;j++)
        {
            if(BlockGroup[i] -> cells[j].edge == 1)
            {
                for(int k = 0;k < MAXNEIGHBOR;k++)
                {
                    if(1)
                    {
                        cell *next = NULL;
                        switch (k) {
                            case 0:
                                next = &BlockGroup[i] -> cells[j] - m;      //上
                                break;
                            case 1:
                                next = &BlockGroup[i] -> cells[j] + 1;      //右
                                break;
                            case 2:
                                next = &BlockGroup[i] -> cells[j] + m;
                                break;
                            case 3:
                                next = &BlockGroup[i] -> cells[j] - 1;
                                break;
                        }
                        if(next != NULL && next -> block_code != BlockGroup[i] -> code)
                        {
                            BlockGroup[i] -> neighbors[k] = BlockGroup[next -> block_code];
                        }
                    }
                }
            }
        }
    }
}

//将Block看作点，用深度优先搜索找到从start到end的最短路径
//具体要求：跨过相邻两个异色块的代价为1，跨过相邻两个同色块的代价为0
//对颜色为-1的块，至多跨过一个无色cell到另一个有色cell，如果同色，代价为2，如果异色，代价为3
//返回值为最短路径的代价
int DFSBlock(block **BlockGroup,int blockcount,block *start,block *end)
{
    int cost = 0;
    if(start == end)
        return 0;
    for(int i = 0;i < MAXNEIGHBOR;i++)
    {
        if(start -> neighbors[i] != NULL)
        {
            if(start -> neighbors[i] == end)
                return 1;
            else
            {
                if(start -> neighbors[i] -> color == -1)
                {
                    for(int j = 0;j < MAXBLOCK;j++)
                    {
                        if(start -> neighbors[i] -> cells[j].color != -1)
                        {
                            if(start -> neighbors[i] -> cells[j].block_code == end -> code)
                            {
                                return 2;
                            }
                            else
                            {
                                return 3;
                            }
                        }
                    }
                }
                else
                {
                    cost = DFSBlock(BlockGroup,blockcount,start -> neighbors[i],end);
                    if(cost != -1)
                    {
                        return cost + 1;
                    }
                }
                
            }
        }
    }
    
}

int main()
{
    FILE *fp = fopen("walk/walk1.in","r");
    int m;
    fscanf(fp,"%d",&m);
    cell **Matrix = (cell **)malloc(m*sizeof(cell *));
    int n;                  //有颜色的cell数（认为-1是无颜色）
    fscanf(fp,"%d",&n);
    for(int i = 0;i < m;i++)
    {
        Matrix[i] = (cell *)malloc(m*sizeof(cell));
        for(int j = 0;j < m;j++)
        {
            Matrix[i][j].color = -1;
            Matrix[i][j].x = i;
            Matrix[i][j].y = j;
            Matrix[i][j].block_code = 0;
            Matrix[i][j].edge = 0;
            for(int k = 0;k < 4;k++)
            {
                Matrix[i][j].direction[k] = 1;
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        int x,y,color;
        fscanf(fp,"%d %d %d",&x,&y,&color);
        Matrix[x-1][y-1].color = color;
    }
    block **BlockGroup = CreateBlocks(Matrix,m);
    block *start = BlockGroup[0];
    int endcode = Matrix[m-1][m-1].block_code;
    block *end = BlockGroup[endcode-1];
    GetBlockNeighbor(BlockGroup,MAXBLOCK,m);
    int cost = 0;
    cost = DFSBlock(BlockGroup,MAXBLOCK,start,end);
    printf("%d\n",cost);

    return 0;

}