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
    FILE *fin = fopen("binary/binary20.in","r");
    FILE *fout = fopen("binary/binary20.out","w");
    long n,m;
    fscanf(fin,"%ld %ld",&n,&m);
    long long *num = (long long *)malloc(2*LIMIT * sizeof(long long));
    for(long long i = 0;i < LIMIT * 2;i++)
        *(num + i) = 0;
    for(long i = 0;i < n;i++)
    {
        long long innum;
        fscanf(fin,"%lld",&innum);
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
        fscanf(fin,"%d",&mode);
        if(DEBUG > 0)
        {
            switch(mode)
            {
                case 1:
                    fscanf(fin,"%ld",&x);
                    *(result + i) = *(num + x + LIMIT);
                    break;
                case 2:
                    fscanf(fin,"%ld %ld",&x,&y);
                    start = x + (STEP - x % STEP);
                    end = y - y % STEP;
                    if(start > end)
                    {
                        for(long j = x;j <= y;j++)
                            *(result + i) += *(num + j + LIMIT);
                        break;
                    }
                    for(long j = start;j <= end;j += STEP)
                        *(result + i) += *(partResult + j / STEP);
                    for(long j = x;j < start;j++)
                        *(result + i) += *(num + j + LIMIT);
                    for(long j = end + 1;j <= y;j++)
                        *(result + i) += *(num + j + LIMIT);
                    break;
                case 3:
                    fscanf(fin,"%ld %ld",&x,&y);
                    y--;
                    start = ((x + STEP - 1)/STEP) * STEP;
                    end = STEP*(y/STEP);
                    if(start > end)
                    {
                        for(long j = x;j <= y;j++)
                            *(result + i) += *(num + j + LIMIT);
                        break;
                    }
                    for(long j = start;j <= end;j += STEP)
                        *(result + i) += *(partResult + j / STEP);
                    for(long j = x;j < start;j++)
                        *(result + i) += *(num + j + LIMIT);
                    for(long j = end + 1;j <= y;j++)
                        *(result + i) += *(num + j + LIMIT);
                    break;
                case 4:
                    fscanf(fin,"%ld %ld",&x,&y);
                    if(i == DEBUG)
                        printf("x = %ld, y = %ld\n",x,y);
                    x++;
                    if(x >= 0)  start = ((x + STEP - 1)/STEP) * STEP;
                    else start = (x/STEP)*STEP;
                    if(y >= 0)  end = (y/STEP - 1)*STEP;
                    else end = (y/STEP - 2)*STEP;
                    if(i == DEBUG)
                       printf("start = %ld, end = %ld\n",start,end);
                    //printList(num,x + LIMIT,y + LIMIT);
                    if(start > end)
                    {
                        for(long j = x;j <= y;j++)
                            *(result + i) += *(num + j + LIMIT);
                        break;
                    }
                    for(long j = start;j <= end;j += STEP)
                    {
                        if(i == DEBUG)
                            printf("Add partResult[%ld] = %ld\n",j,*(partResult + j / STEP + LIMIT/STEP));
                        *(result + i) += *(partResult + j / STEP + LIMIT/STEP);
                    }
                    for(long j = x;j < start;j++)
                    {   
                        if(i == DEBUG)
                            printf("Add num[%ld] = %ld\n",j,*(num + j + LIMIT));
                        *(result + i) += *(num + j + LIMIT);
                    }
                    for(long j = end + STEP;j <= y;j++)
                    {
                        if(i == DEBUG)
                            printf("Add num[%ld] = %ld\n",j,*(num + j + LIMIT));
                        //printf("Add num[%ld] = %ld\n",j,*(num + j + LIMIT));
                        *(result + i) += *(num + j + LIMIT);
                    }
                    break;
                case 5:
                    fscanf(fin,"%ld %ld",&x,&y);
                    x++;y--;
                    start = x + (STEP - x % STEP);
                    end = y - y % STEP;
                    if(start > end)
                    {
                        for(long j = x;j <= y;j++)
                            *(result + i) += *(num + j + LIMIT);
                        break;
                    }
                    for(long j = start;j <= end;j += STEP)
                        *(result + i) += *(partResult + j / STEP);
                    for(long j = x;j < start;j++)
                        *(result + i) += *(num + j + LIMIT);
                    for(long j = end + 1;j <= y;j++)
                        *(result + i) += *(num + j + LIMIT);
                    break;
                default:
            }
        }
        else
        {
            fscanf(fin,"%ld %ld",&x,&y);
        }
            
    }

    for(long i = 0;i < m;i++)
    {
        fprintf(fout,"%ld\n",*(result + i));
        if(i == DEBUG)
            printf("result %ld = %ld\n",i,*(result + i));
    }

    free(num);
    free(result);
    free(partResult);
    fclose(fin);
    fclose(fout);
    return 0;
}