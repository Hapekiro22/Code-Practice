#include <stdio.h>
#include <stdlib.h>
#define LIMIT 250000
#define STEP 500
#define DEBUG 5
void printList(long long *list,long start,long end)
{
    for(long i = start;i <= end;i++)
        printf("num %ld: %ld\n",i - LIMIT,*(list + i));
    printf("\n");
}

int main()
{
    //FILE *fin = fopen("binary/binary19.in","r");
    //FILE *fout = fopen("binary/binary19.out","w");
    long n,m;
    scanf("%ld %ld",&n,&m);
    long long *num = (long long *)malloc(2*LIMIT * sizeof(long long));
    for(long long i = 0;i < LIMIT * 2;i++)
        *(num + i) = 0;
    for(long i = 0;i < n;i++)
    {
        long long innum;
        scanf("%lld",&innum);
        (*(num + innum + LIMIT))++;
    }

    long *result = (long *)malloc(m * sizeof(long));
    for(long i = 0;i < m;i++)
        *(result + i) = 0;
    long *partResult = (long *)malloc((2 *LIMIT / STEP) * sizeof(long));
    for(long i = 0;i < LIMIT * 2;i += STEP)
    {
        long sum = 0;
        for(long j = i;j < i + STEP;j++)
            sum += *(num + j);
        *(partResult + i / STEP) = sum;
        //if(sum)   printf("part %ld = %ld\n",i / STEP,sum);
    }

    long x,y;
    long start,end;
    for(long i = 0;i < m;i++)
    {
        int mode;
        scanf("%d",&mode);
        switch(mode)
        {
            case 1:
                scanf("%ld",&x);
                *(result + i) = *(num + x + LIMIT);
                break;
            case 2:
                scanf("%ld %ld",&x,&y);
                if(x >= 0)  start = ((x + STEP - 1)/STEP) * STEP;
                else start = (x/STEP)*STEP;
                if(y >= 0)  end = (y/STEP - 1)*STEP;
                else end = (y/STEP - 2)*STEP;
                if(start > end)
                {
                    for(long j = x;j <= y;j++)
                        *(result + i) += *(num + j + LIMIT);
                    break;
                }
                for(long j = start;j <= end;j += STEP)
                {
                    *(result + i) += *(partResult + j / STEP + LIMIT/STEP);
                }
                for(long j = x;j < start;j++)
                {   
                    *(result + i) += *(num + j + LIMIT);
                }
                for(long j = end + STEP;j <= y;j++)
                {
                    *(result + i) += *(num + j + LIMIT);
                }
                break;
            case 3:
                scanf("%ld %ld",&x,&y);
                y--;
                if(x >= 0)  start = ((x + STEP - 1)/STEP) * STEP;
                else start = (x/STEP)*STEP;
                if(y >= 0)  end = (y/STEP - 1)*STEP;
                else end = (y/STEP - 2)*STEP;
                if(start > end)
                {
                    for(long j = x;j <= y;j++)
                        *(result + i) += *(num + j + LIMIT);
                    break;
                }
                for(long j = start;j <= end;j += STEP)
                {
                    *(result + i) += *(partResult + j / STEP + LIMIT/STEP);
                }
                for(long j = x;j < start;j++)
                {   
                    *(result + i) += *(num + j + LIMIT);
                }
                for(long j = end + STEP;j <= y;j++)
                {
                    *(result + i) += *(num + j + LIMIT);
                }
                break;
            case 4:
                scanf("%ld %ld",&x,&y);
                x++;
                if(x >= 0)  start = ((x + STEP - 1)/STEP) * STEP;
                else start = (x/STEP)*STEP;
                if(y >= 0)  end = (y/STEP - 1)*STEP;
                else end = (y/STEP - 2)*STEP;
                if(start > end)
                {
                    for(long j = x;j <= y;j++)
                        *(result + i) += *(num + j + LIMIT);
                    break;
                }
                for(long j = start;j <= end;j += STEP)
                {
                    *(result + i) += *(partResult + j / STEP + LIMIT/STEP);
                }
                for(long j = x;j < start;j++)
                {   
                    *(result + i) += *(num + j + LIMIT);
                }
                for(long j = end + STEP;j <= y;j++)
                {
                    *(result + i) += *(num + j + LIMIT);
                }
                break;
            case 5:
                scanf("%ld %ld",&x,&y);
                x++;y--;
                if(x >= 0)  start = ((x + STEP - 1)/STEP) * STEP;
                else start = (x/STEP)*STEP;
                if(y >= 0)  end = (y/STEP - 1)*STEP;
                else end = (y/STEP - 2)*STEP;
                if(start > end)
                {
                    for(long j = x;j <= y;j++)
                        *(result + i) += *(num + j + LIMIT);
                    break;
                }
                for(long j = start;j <= end;j += STEP)
                {
                    *(result + i) += *(partResult + j / STEP + LIMIT/STEP);
                }
                for(long j = x;j < start;j++)
                {   
                    *(result + i) += *(num + j + LIMIT);
                }
                for(long j = end + STEP;j <= y;j++)
                {
                    *(result + i) += *(num + j + LIMIT);
                }
                break;
            default:
        }
            
    }

    for(long i = 0;i < m;i++)
    {
        printf("%ld\n",*(result + i));
    }

    free(num);
    free(result);
    free(partResult);
    //fclose(fin);
    //fclose(fout);
    return 0;
}