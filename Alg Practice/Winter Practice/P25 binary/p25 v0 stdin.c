#include <stdio.h>
#include <stdlib.h>
#define LIMIT 250000
#define STEP 500

int main()
{
    //FILE *fin = fopen("binary/binary20.in","r");
    //FILE *fout = fopen("binary/binary20.out","w");
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
    long *partResult = (long *)malloc((LIMIT / STEP) * sizeof(long));
    for(long i = 0;i < LIMIT * 2;i += STEP)
    {
        long sum = 0;
        for(long j = i;j < i + STEP;j++)
            sum += *(num + j);
        *(partResult + i / STEP) = sum;
    }
    long x,y;
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
                long start = x + (STEP - x % STEP);
                long end = y - y % STEP;
                for(long j = start;j <= end;j += STEP)
                    *(result + i) += *(partResult + j / STEP);
                for(long j = x;j < start;j++)
                    *(result + i) += *(num + j + LIMIT);
                for(long j = end + STEP;j <= y;j++)
                    *(result + i) += *(num + j + LIMIT);
                break;
            case 3:
                scanf("%ld %ld",&x,&y);
                start = x + (STEP - x % STEP);
                end = y - y % STEP;
                for(long j = start;j < end;j += STEP)
                    *(result + i) += *(partResult + j / STEP);
                for(long j = x;j < start;j++)
                    *(result + i) += *(num + j + LIMIT);
                for(long j = end;j <= y;j++)
                    *(result + i) += *(num + j + LIMIT);
                break;
            case 4:
                scanf("%ld %ld",&x,&y);
                start = x + (STEP - x % STEP);
                end = y - y % STEP;
                for(long j = start + STEP;j <= end;j += STEP)
                    *(result + i) += *(partResult + j / STEP);
                for(long j = x + 1;j < start;j++)
                    *(result + i) += *(num + j + LIMIT);
                for(long j = end + 1;j <= y;j++)
                    *(result + i) += *(num + j + LIMIT);
                break;
            case 5:
                scanf("%ld %ld",&x,&y);
                start = x + (STEP - x % STEP);
                end = y - y % STEP;
                for(long j = start + STEP;j < end;j += STEP)
                    *(result + i) += *(partResult + j / STEP);
                for(long j = x + 1;j < start;j++)
                    *(result + i) += *(num + j + LIMIT);
                for(long j = end;j <= y;j++)
                    *(result + i) += *(num + j + LIMIT);
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
    return 0;
}