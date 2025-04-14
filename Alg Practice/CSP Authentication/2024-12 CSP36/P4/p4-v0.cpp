#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

#define DEBUG 1

using namespace std;

typedef struct Point 
{
    int series;
    long step;
    long retreat;
} point, *pointPtr;

typedef struct Group
{
    pointPtr pMax,pMin;
    int series;
    long step;
    Group **neighbor;
} group;

/*

    生成一个二元点对：
    1. max点是当前点，min点是后退的点
    2. 用较小点代替group的位置(series)
    3. neighbor是从min点开始的step个group

*/

group *linkPoints(point *pointGroups, int num); 
void Nalloc(group *groups, int num);
int findMinPath(group *groups, int num);

int main()
{
    FILE *fin = fopen("evaldata/p4-1.in","r");
    FILE *fout = fopen("evaldata/p4-0.out","w");

    int n;
    fscanf(fin,"%d",&n);
    point *pointGroups = new point[n];
    for(int i = 0;i < n;i++)
    {
        fscanf(fin,"%ld %ld",&pointGroups[i].retreat,&pointGroups[i].step);
        pointGroups[i].series = i;
    }

    group *groups = linkPoints(pointGroups,n);
    Nalloc(groups,n);

    int count = 0;
    count = findMinPath(groups,n);

    fprintf(fout,"%d\n",count);

    fclose(fin);
    fclose(fout);
    return 0;

}

group *linkPoints(point * pointGroups, int num) 
{
    group *groups = new group[num];
    for(int i = 0;i < num;i++)
    {
        groups[i].pMin = &pointGroups[i - pointGroups[i].retreat];
        groups[i].pMax = &pointGroups[i];
        groups[i].series = i;
        groups[i].step = pointGroups[i - pointGroups[i].retreat].step;
        groups[i].neighbor = NULL;
    }

    return groups;
}

void Nalloc(group *groups, int num)
{
    for(int i = 0;i < num;i++)
    {
        groups[i].neighbor = new group*[groups[i].step];
        for(int j = 0;j < groups[i].step;j++)
        {
            group *next = &groups[groups[i].pMin->series + j];
            groups[i].neighbor[j] = next;
        }   
    }
    return;
}


//从一号点开始，到达n好点，找到最小路径
//行走规则：每次最多向前走step步，到达一点后要后退retreat步
//采用广度优先搜索
int findMinPath(group *groups, int num)
{
    queue<pair<group*,int>> q;
    vector<bool> visited(num,false);

    int count = 0;
    group *start = &groups[0];
    group *end = &groups[num - 1];

    q.push({start,0});
    visited[start->series] = true;

    while(!q.empty())
    {
        auto [current,steps] = q.front();
        q.pop();

        if(current == end)
        {
            return steps;
        }

#ifdef DEBUG
        cout << "current: " << current->series << " steps: " << steps << endl;
#endif


        for(int i = 0; i < current->step; i++)
        {
            group *next = current->neighbor[i];

            if(!visited[next->series])
            {
                q.push({next,steps + 1});
                visited[next->series] = true;
            }

#ifdef DEBUG
            cout << "next: " << next->series << " steps: " << steps + 1 << endl;
#endif

        }
    }

    return -1;
}