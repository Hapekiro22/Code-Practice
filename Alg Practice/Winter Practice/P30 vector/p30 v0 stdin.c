#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
    long long *series;
    int number;
    int dim;
}vector;

int cmpvector(vector vector1,vector vector2)       //若2比1大，则返回1
{
    if (vector1.dim != vector2.dim) {
        return 0;
    }
    int m = vector1.dim;
    for(int i = 0;i < m;i++)
    {
       // printf("compare %lld and %lld\n",vector1.series[i],vector2.series[i]);
        if(vector1.series[i] > vector2.series[i])
            return 0;
    }
    return 1;
}

int main()
{
    //FILE *fp = fopen("vector/vector1.in","r");
    int n,m;
    scanf("%d %d",&n,&m);
    vector *group = (vector *)malloc(n*sizeof(vector));
    for(int i = 0;i < n;i++)
    {
        group[i].series = (long long *)malloc(m*sizeof(long long));
        for(int j = 0;j < m;j++)
        {
            long long num;
            scanf("%lld",&num);
            group[i].series[j] = num;
            (group + i) -> number = i;
            (group + i) -> dim = m;
            //printf("%lld ",group[i].series[j]);
        }
    }
    //fclose(fp);

    for(int i = 0;i < n;i++)
    {
        int flag = 0;
        for(int j = 0;j < n;j++)
        {
            if(j == i) continue;
            if(cmpvector(group[i],group[j]))
            {
                //printf("%d\n",(group + j) -> number + 1);
                printf("%d\n",j + 1);
                flag = 1;
                break;
            }
        }
        if(flag == 0) printf("0\n");
    }

    for(int i = 0;i < n;i++)
        free(group[i].series);
    free(group);
    return 0;
}