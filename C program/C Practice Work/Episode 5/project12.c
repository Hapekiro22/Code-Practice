//一个0-1迷宫，1表示可以走，0表示不能走，求从左上角到右下角的所有路径
#include <stdio.h>
#include <malloc.h>

void MazeSolve(int maze[][100],int row,int col);
void PrintPath(int **path,int maze[][100],int row,int col);
void ClearPath(int **path,int maze[][100],int count,int row,int col);
int Checkway(int maze[][100],int row,int col,int x,int y);           //检查是否可以走,返回值是可以走的方向数0,1,2,3,4

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
    int temp[100][100];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            temp[i][j] = maze[i][j];
        }
    }
    int **path = (int **)malloc(row*col*sizeof(int *));                             //path是一个指针数组，存储了当前路上所有节点的地址
    int *ways = (int *)malloc(row*col*sizeof(int));                                 //ways存储对应节点的方向数
    for(int i =0;i<row*col;i++) path[i] = NULL;                                      //初始化path
    int count = 0,end=0;                                                             //count是当前路上的节点数
    int *p = &maze[0][0]; 
    int x = 0, y = 0,flag = 1;                                                          //p是当前节点的地址         
    while(1)                                                              //当起点还有可行的方向时，继续循环
    {                                                                                                             //如果end为1，说明已经到达终点，count清零,重新开始
        if(x==0&&y==0) count = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(&maze[i][j]==p) {x = i;y = j;break;}                             //找到当前节点的坐标
            }
        }
        p = &maze[x][y];
        //printf("after%d %d %d ",x,y,count);
        maze[x][y] = 0;                                                             //将当前节点标记为已走过
        path[count] = p;
        ways[count] = Checkway(maze,row,col,x,y);
        if(x==row-1&&y==col-1) {p = path[count-1];flag = 0;PrintPath(path,maze,row,col);} 
        //printf("%d \n",ways[count]);
        if(ways[count]==0)                                                          //如果当前节点没有可行的方向
        {
            if(count==0) break;                                                    //如果当前节点是起点，且没有可行的方向，结束循环
            else
            {
                flag = 0;
                maze[x][y] = 0;                                                    //如果当前节点不是起点，且没有可行的方向，将当前节点标记为未走过,回退直到有可行的方向
                count--;
                p = path[count];
                printf("%d %d %d %d\n",x,y,count+1,*path[count+1]); 
                printf("Return to %d step\n",count);
                ClearPath(path,maze,count,row,col); printf("Clear\n");if(count==9) {printf("%d ",maze[2][5]);}
                continue;
            }

        }               
        if(ways[count]!=0)
        {
            if(!flag) {ClearPath(path,maze,count,row,col);flag = 1;printf("Clear\n");}  //如果已经到达终点，清除路径
            int newX,newY;
            if(x>=0&&x<row&&y+1>=0&&y+1<col&&maze[x][y+1]==1) {newX = x;newY = y+1;}  //找到新节点的坐标
            else if(x+1>=0&&x+1<row&&y>=0&&y<col&&maze[x+1][y]==1) {newX = x+1;newY = y;}
            else if(x>=0&&x<row&&y-1>=0&&y-1<col&&maze[x][y-1]==1) {newX = x;newY = y-1;}
            else if(x-1>=0&&x-1<row&&y>=0&&y<col&&maze[x-1][y]==1) {newX = x-1;newY = y;}
            p = &maze[newX][newY];
            ways[count]--;                                                             //将当前节点的方向数减1
            ways[++count] = Checkway(maze,row,col,newX,newY);                            //将新节点的方向数存入ways
            printf("%d %d step%d %d\n",newX,newY,count,ways[count]);                                     
        } 
        
    }
}

int Checkway(int maze[][100],int row,int col,int x,int y)
{
    int way = 0;
    if(x>=0&&x<row&&y+1>=0&&y+1<col&&maze[x][y+1]==1) way++;
    if(x+1>=0&&x+1<row&&y>=0&&y<col&&maze[x+1][y]==1) way++;
    if(x>=0&&x<row&&y-1>=0&&y-1<col&&maze[x][y-1]==1) way++;
    if(x-1>=0&&x-1<row&&y>=0&&y<col&&maze[x-1][y]==1) way++;
    return way;
}

void ClearPath(int **path,int maze[][100],int count,int row,int col)
{
    int i,j;
    for(int k = count+2;path[k]!=NULL;k++)
    {
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(&maze[i][j]==path[k]) maze[i][j] = 1;
            }
        }
        path[k] = NULL;
    }
   // path[count+1] = NULL;
}

void PrintPath(int **path,int maze[][100],int row,int col)
{
    printf("Path:\n");
    int i,j;
    for(int k=0;path[k]!=NULL;k++)
    {
        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(&maze[i][j]==path[k]) {maze[i][j] = 2; break;}
            }
        }
       
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(maze[i][j]==2) printf("1 ");
            else printf("0 ");
        }
        printf("\n");
    }
    printf("\n");
}