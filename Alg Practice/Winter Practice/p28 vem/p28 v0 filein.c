#include <stdio.h>
#include <stdlib.h>
#define MAXSERIES 20000

int main()
{
    FILE *fp = fopen("vem/vem7-3-1.in","r");
    int n,m,k;
    fscanf(fp,"%d %d %d",&n,&m,&k);
    long *object = (long *)malloc(MAXSERIES * sizeof(long));
    if(object == NULL)
    {
        printf("malloc failed\n");
        return 0;
    }
    for(int i = 0;i < MAXSERIES;i++)
        object[i] = 0;
    int maxs = 0;
    for(int i = 0;i < k;i++)
    {
        int series;
        fscanf(fp,"%d",&series);
        if(series > maxs)
            maxs = series;
        object[series]++;
    }
    int currow = maxs,rowremain = m;
    printf("maxs = %d,currow = %d,rowremain = %d\n",maxs,currow,rowremain);
    if(currow > n)
        currow = n;
    while(currow > 0 && k > 0)
    {
        //printf("object[%d] = %d\n",maxs,object[maxs]);
        if(object[maxs] > 0)
        {
            rowremain--;
            object[maxs]--;
            k--;
            printf("put %d in row %d\n",maxs,currow);
        }
        if(rowremain == 0)
        {
            currow--;
            rowremain = m;
        }
        if(object[maxs] <= 0)
            maxs--;
        currow = currow > maxs ? maxs : currow;
    }

    printf("currow = %d,rowremain = %d\n",currow,rowremain);
    printf("k = %d\n",k);
    if(k > 0)
        printf("No\n");
    if(k == 0)
        printf("Yes\n");
    
    free(object);
    fclose(fp);
    return 0;
    
}