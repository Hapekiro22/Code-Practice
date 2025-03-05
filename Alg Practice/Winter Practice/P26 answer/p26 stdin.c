#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 1000000000
#define NUMLEN 20
#define CNUM 3
#define STEP 10000

long transformNum(char *num);

int main()
{
   //FILE *fin = fopen("answer/answer20.in","r");
    //FILE *fout = fopen("answer/answer20.out","w");
    long long n,Q;
    scanf("%lld %lld",&n,&Q);
    getchar();

    long long max = 0;
    long long min = LIMIT;
    int *solveCount = (int *)malloc(LIMIT * sizeof(int));
    if(solveCount == NULL)
    {
        printf("malloc failed\n");
        return 0;
    }
    for(long long i = 0;i < LIMIT;i++,solveCount[i] = 0);
    for(long long i = 0;i < n;i++)
    {
        printf("round %d\n",i);
        char c;
        long *num = (long *)malloc(CNUM * sizeof(long));
        for(int j = 0;j < CNUM;j++)
            *(num + j) = 0;
        long *p = num;
        //printf("num = %ld %ld %ld\n",*p,*(p + 1),*(p + 2));
        int mark[CNUM] = {0};
        while((c = getchar()) != '\n')
        {
            //printf("c = %c\n",c);
            if(c >= '0' && c <= '9')
            {
                *p = (*p) * 10;
                *p += c - '0';
            }
            else if(c == '-') mark[(int)(p - num)] = 1;
            else if(c == '+') continue;
            else p++;
        }
        p = num;
        for(int j = 0;j < CNUM;j++)
            if(mark[j]) *(p + j) *= -1; 
        long solve = (num[2] - num[1]) / num[0];
        if(solve > max) max = solve;
        if(solve < min) min = solve;
        //printf("solve = %ld\n",solve);
        solveCount[solve] = 1;
        free(num);
    }

    min = ((min + STEP - 1)/ STEP) * STEP;
    max = (max / STEP) * STEP;

    long *result = (long *)malloc(Q * sizeof(long));
    for(long i = 0;i < Q;i++)
        *(result + i) = 0;
    long *partResult = (long *)malloc((LIMIT / STEP) * sizeof(long));
    for(long i = min;i < max;i += STEP)
    {
        //printf("round %ld\n",i);
        long sum = 0;
        for(long j = i;j < i + STEP;j++)
            sum += *(solveCount + j);
        *(partResult + i / STEP) = sum;
    }

    for(long i = 0;i < Q;i++)
    {
        //printf("round %ld\n",i);
        long x,y;
        long start,end;
        scanf("%ld %ld",&x,&y);
        start = ((x + STEP - 1)/STEP) * STEP;
        end = (y/STEP - 1)*STEP;
        //printf("x = %ld, y = %ld, start = %ld, end = %ld\n",x,y,start,end);
        if(start > end)
        {
            for(long j = x;j <= y;j++)
            {
                *(result + i) += *(solveCount + j);
                //if(i == 999) printf("Add %ld and the result is %ld\n",*(solveCount + j),*(result + i));
            }
            continue;
        }
        for(long j = start;j <= end;j += STEP)
        {
            *(result + i) += *(partResult + j / STEP );
        }
        for(long j = x;j < start;j++)
        {   
            *(result + i) += *(solveCount + j );
        }
        for(long j = end + STEP;j <= y;j++)
        {
            *(result + i) += *(solveCount + j );
        }
    }

    for(long i = 0;i < Q;i++)
    {
        printf("%ld\n",*(result + i));
    }
    
    //fclose(fin);
    //fclose(fout);
    //free(solveCount);
    return 0;
}