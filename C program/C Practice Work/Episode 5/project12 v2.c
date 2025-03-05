// Problem: 12.迷宫问题（Maze Problem）
//利用深度优先搜索和回溯找到所有的路径
//采用递归的方法，每次递归的时候，将当前节点的地址存入path数组中，然后检查当前节点的可行方向，如果有可行方向，就继续递归，如果没有可行方向，就回溯到上一个节点，直到回溯到起点
#include<stdio.h>
#include<stdlib.h>

void MazeSolve(int maze[][100],int row,int col);
void PrintPath(int **path,int maze[][100],int row,int col);
void ClearPath(int **path,int maze[][100],int *ways,int count,int *waysc,int row,int col);     //清除走不通的路的地址和方向数
void Getlocation(int maze[][100],int row,int col,int *x,int *y,int *p);                        //获取当前节点的位置
int Checkway(int maze[][100],int row,int col,int x,int y,int ways[4]);                         //检查是否可以走,返回值是可以走的方向数0,1,2,3,4
int Checkreturn(int **path,int maze[][100],int row,int col,int x,int y,int count);             //检查是否走回头路

int main()
{
    int row,col;
    scanf("%d %d",&row,&col);
    int maze[100][100];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }
    MazeSolve(maze,row,col);
    return 0;
}

void MazeSolve(int maze[][100],int row,int col)
{
    int **path = (int **)malloc(row*col*sizeof(int *));                             //path是一个指针数组，存储了当前路上所有节点的地址
    int ways[100][4],waysc[100] = {0};                                               //ways存储对应节点的可行方向，每个一维数组存储一个节点的可行方向
    for(int i =0;i<row*col;i++) path[i] = NULL;                                      //初始化path
    int *p = &maze[0][0];
    int x = 0, y = 0,count = 0,flag = 1;
    while(1)
    {
        if(x==0&&y==0) count = 0;
        Getlocation(maze,row,col,&x,&y,p);
        p = &maze[x][y];
        path[count] = p; 
        if(flag) waysc[count] = Checkway(maze,row,col,x,y,ways[count]);                                                    //如果是回溯的话，不需要再次检查可行方向，当走到新的节点时，需要检查可行方向
        //printf("way right:%d down:%d left:%d up:%d\n",ways[count][0],ways[count][1],ways[count][2],ways[count][3]);
        if(x==row-1&&y==col-1) {p = path[count-1];PrintPath(path,maze,row,col);}
        int newX,newY;
        if(ways[count][0]==1&&(Checkreturn(path,maze,row,col,x,y+1,count))) {newX = x;newY = y+1;ways[count][0] = 0;}      //判断下一个节点的位置,并且不走回头路
        else if(ways[count][1]==1&&(Checkreturn(path,maze,row,col,x+1,y,count))) {newX = x+1;newY = y;ways[count][1] = 0;}
        else if(ways[count][2]==1&&(Checkreturn(path,maze,row,col,x,y-1,count))) {newX = x;newY = y-1;ways[count][2] = 0;}
        else if(ways[count][3]==1&&(Checkreturn(path,maze,row,col,x-1,y,count))) {newX = x-1;newY = y;ways[count][3] = 0;}
        else waysc[count] = 0;
        if(waysc[count]==0)
        {
            if(count==0) break;
            else
            {
                ClearPath(path,maze,ways[count],count,&waysc[count],row,col);                   //清除走不通的路的地址和方向数
                p = path[--count];                                                              //回溯
                //printf("Return from x:%d y:%d,to step %d\n",x,y,count);
                flag = 0;                                                                       //当前是回溯状态                 
                continue;
            }
        }
        flag = 1;                                                                                //当前是新的节点                       
        p = &maze[newX][newY];
        waysc[count++]--;                                                                        //可行方向数减一
        //waysc[count] = Checkway(maze,row,col,newX,newY,ways[count]);                            
        //printf("x:%d y:%d count:%d\n",newX,newY,count);
    }                                                      
}

int Checkway(int maze[][100],int row,int col,int x,int y,int ways[4])
{
    int way = 0;
    if(x>=0&&x<row&&y+1>=0&&y+1<col&&maze[x][y+1]==1) {ways[0] = 1;way++;} else ways[0] = 0;
    if(x+1>=0&&x+1<row&&y>=0&&y<col&&maze[x+1][y]==1) {ways[1] = 1;way++;} else ways[1] = 0;
    if(x>=0&&x<row&&y-1>=0&&y-1<col&&maze[x][y-1]==1) {ways[2] = 1;way++;} else ways[2] = 0;
    if(x-1>=0&&x-1<row&&y>=0&&y<col&&maze[x-1][y]==1) {ways[3] = 1;way++;} else ways[3] = 0;
    return way;
}

void Getlocation(int maze[][100],int row,int col,int *x,int *y,int *p)
{
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<col;j++)
        {
            if(&maze[i][j]==p) {*x = i;*y = j;break;}
        }
    }
}

void ClearPath(int **path,int maze[][100],int *ways,int count,int *waysc,int row,int col)
{
    int x,y;
    Getlocation(maze,row,col,&x,&y,path[count]);
    //*waysc = Checkway(maze,row,col,x,y,ways);
    path[count] = NULL;
}

int Checkreturn(int **path,int maze[][100],int row,int col,int x,int y,int count)             //检查是否走回头路
{
    int i,j;
    for(int k = 0;k<count;k++)
    {
        Getlocation(maze,row,col,&i,&j,path[k]);
        if(x==i&&y==j) return 0;
    }
    return 1;
}

void PrintPath(int **path,int maze[][100],int row,int col)
{
    printf("Path:\n");
    int i,j;
    for(int k=0;path[k]!=NULL;k++)
    {
        Getlocation(maze,row,col,&i,&j,path[k]);
        maze[i][j] = 2;
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==0&&j==0) printf("1 ");
            else if(maze[i][j]==2)   {printf("1 "); maze[i][j] = 1;}
            else printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}