//输入n，k，和n个二维坐标
//将n个点分成k组，规定两组之间的距离为两组中所有点之间的距离的最小值
//求一个适当的划分，使得最小组间距离最大
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Point
{
    int x;
    int y;
    int groupnum;
    double *distance;
    struct Point **neighbour; 
    struct Point *next;
    struct Point *former;   
}Point;

double distance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void dissort(Point p,int n)      //返回p到最近的点的距离,nearest为最近点的下标
{
    for(int i=n-1;i>=0;i--)            //冒泡排序,所有点按照到p的距离从小到大排序
    {
        for(int j=0;j<i;j++)
        {
            if(p.distance[j] > p.distance[j+1])
            {
                double temp = p.distance[j];
                p.distance[j] = p.distance[j+1];
                p.distance[j+1] = temp;
                Point *temp1 = p.neighbour[j];
                p.neighbour[j] = p.neighbour[j+1];
                p.neighbour[j+1] = temp1;
            }
        }
    }                                   
}                        

int main()
{
    int n,k;
    //printf("Please input n and k:\n");
    scanf("%d %d",&n,&k);
    //printf("Please input %d points:\n",n);
    Point *p = (Point*)malloc(n * sizeof(Point));                   //p[i]表示第i个点
    for(int i=0;i<n;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
    for(int i=0;i<n;i++)
    {
        p[i].distance = (double*)malloc(n * sizeof(double));
        for(int j=0;j<n;j++)
            p[i].distance[j] = distance(p[i], p[j]);
        p[i].next = NULL;
        p[i].former = NULL;
        p[i].groupnum = 10000;                                      //初始化为10000,表示未分组
    }
    for(int i=0;i<n;i++)
    {
        p[i].neighbour = (Point**)malloc(n * sizeof(Point*));
        for(int j=0;j<n;j++)
            p[i].neighbour[j] = &p[j];
    }
    Point **group = (Point**)malloc(k * sizeof(Point*));             //group[i]表示第i组的第一个点,group[i]->next表示第i组的第二个点
    for(int i=0;i<k;i++)
        group[i] = NULL;
    for(int i=0;i<n;i++)
        {
            dissort(p[i],n);
            p[i].next = p[i].neighbour[0]; 
        }
    double max = 0;
    for(int i=0;i<k;i++)
    {
        int maxindex = 0;
        double temp = max;
        max = 0;
        for(int j=0;j<n&&group[i]==NULL;j++)
        {
            if((p[j].distance[1] > max) && (p[j].groupnum>=i))
            {
                printf("p[%d].distance = %lf\n",j,p[j].distance[1]);
                printf("groupnum = %d\n",p[j].groupnum);
                max = p[j].distance[1];
                printf("max = %lf\n",max);
                maxindex = j;
            }
        }
        group[i] = &p[maxindex];
        printf("Put point %d into group %d\n",maxindex+1,i);
        p[maxindex].groupnum = i;
        //printf("groupnum new = %d\n",p[i].groupnum);                                             //标记为已经分组
        Point *pList = p[i].neighbour[1];                                                
        while(1)
        {
            int j = 0;
            if((*pList).distance[1] <= max)
            {
                p[i].next = NULL;
                printf("There is no other point in group %d\n",i);
                break;                                                  //如果最近的点到最近的点的距离小于max,则停止
            }
            else
            {
                pList->next = pList->neighbour[1];
                pList->groupnum = i;
                pList = pList->next;
                max = (*pList).distance[1];
            }                                                           //否则加入该组,并继续
            printf("Put a point %d into group %d\n",i+j+1,i);
        }
        if(max > temp && i > 0) max = temp;
        
    }
    printf("The result is: %lf\n",max);
    return 0;
}



//max 问题未能解决
//未能实现新取出的点对所有已经分组的点的距离的最小值大于max的条件