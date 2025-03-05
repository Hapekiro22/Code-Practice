j#include<stdio.h>
#include<string.h>
#define N 1001
struct st{
    int x;
    int y;
}s[N];//记录路径坐标的栈 
int Map[N][N];//地图
int step[N][N];//路径地图 
int flag[N][N];//标记地图 
int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//方向 上，右，左，下 
int n,m,k=1,num=1;
void input()
{
    s[0].x=s[0].y=1;
    for(int i=0;i<k;i++)
    {
        int x=s[i].x;
        int y=s[i].y;
        step[x][y]=1;//标记路径 
        //printf("(%d,%d) ",x,y);
    }
    printf("%d\n",num++);//输出路径编号 
    for(int i=1;i<=n;i++)//输出地图路径 
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d",step[i][j]);
            if(j!=m)
            printf(" ");
        }
        printf("\n");
    }
    memset(step,0,sizeof(step));//路径地图置0，防止干扰下次输出 
}
void dsf(int x,int y)
{
    if(x==n&&y==m)
    {//到达终点,输出 
        input(); 
        return;
    }
    int nx,ny;
    for(int i=0;i<4;i++)
    {
        nx=x+next[i][0];
        ny=y+next[i][1];
        if(nx<=n&&ny<=m)//判断是否越界,是否可通过 
        if(flag[nx][ny]==0&&Map[nx][ny]==1)
        {
            flag[nx][ny]=1;
            s[k].x=nx;// 记录路径上的坐标 (入栈)
            s[k++].y=ny;//记录路径上的坐标 (入栈) 
            dsf(nx,ny);//前往下一个点 
            flag[nx][ny]=0;//回溯(走过的路,退回) 
            k--;//(出栈)
        }
    }    
}

int main() 
{
    memset(Map,0,sizeof(Map));//置0 
    memset(flag,0,sizeof(flag));
    scanf("%d%d",&n,&m);//行 列 
    for(int i=1;i<=n;i++)//地图 
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&Map[i][j]);
        }
    }
    dsf(1,1);//从左上角开始,向右下角走 
    return 0;
}