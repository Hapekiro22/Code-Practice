#include <stdio.h>
#include <stdlib.h>
#define MAXSERIES 20000

int main()
{
    //FILE *fp = fopen("vem/vem7-5-3.in","r");
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
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
        scanf("%d",&series);
        if(series > maxs)
            maxs = series;
        object[series]++;
    }
    int currow = maxs,rowremain = m;
    //printf("maxs = %d,currow = %d,rowremain = %d\n",maxs,currow,rowremain);
    while(currow > 0 && k > 0)
    {
        //printf("object[%d] = %d\n",maxs,object[maxs]);
        if(object[maxs] > 0)
        {
            rowremain--;
            object[maxs]--;
            k--;
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

    //printf("currow = %d,rowremain = %d\n",currow,rowremain);
    //printf("%d\n",k);
    if(k > 0)
        printf("No\n");
    if(k == 0)
        printf("Yes\n");
    
    free(object);
    //fclose(fp);
    return 0;
    
}