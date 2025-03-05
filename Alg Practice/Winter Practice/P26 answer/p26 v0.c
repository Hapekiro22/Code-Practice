#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 999999999
#define NUMLEN 20
#define CNUM 3
#define STEP 100

long transformNum(char *num);

int main()
{
    FILE *fin = fopen("answer/answer10.in","r");
    FILE *fout = fopen("answer/answer10.out","w");
    long long n,Q;
    fscanf(fin,"%lld %lld",&n,&Q);
    fgetc(fin);

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
        //printf("round %d\n",i);
        char c;
        long *num = (long *)malloc(CNUM * sizeof(long));
        for(int j = 0;j < CNUM;j++)
            *(num + j) = 0;
        long *p = num;
        //printf("num = %ld %ld %ld\n",*p,*(p + 1),*(p + 2));
        int mark[CNUM] = {0};
        while((c = fgetc(fin)) != '\n')
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

    long long half = LIMIT / 2;
    long long len = LIMIT / STEP;
    long long *compressed = (long long *)malloc(len * sizeof(long long));
    for(long long i = 0;i < len;i++)
        compressed[i] = 0;
    printf("min = %d, max = %d\n",min,max);
    for(int i = (min + (STEP-min%STEP));i < max - max%STEP;i += STEP)
    {
        long long sum = 0;
        for(int j = 0;j < STEP;j++)
            sum += solveCount[i + j];
        compressed[i / STEP] = sum;
        printf("compressed[%d] = %d\n",i / STEP,compressed[i / STEP]);
    }
    for(long long i = 0;i < Q;i++)
    {
        //printf("round %d\n",i);
        long long count = 0;
        long long start,end;
        fscanf(fin,"%lld %lld",&start,&end);
        long long startstep = start + (STEP - start % STEP);
        long long endstep = end - end % STEP;
        if(startstep < endstep)
        {
            for(long long j = startstep;j < endstep;j += STEP)
                count += compressed[j / STEP];        
            for(long long j = start;j < startstep;j++)
                count += solveCount[j];
            for(long long j = endstep + 1;j <= end;j++)
                count += solveCount[j];
        }
        else
        {
            for(long long j = start;j <= end;j++)
                count += solveCount[j];
        }
        //printf("start = %d, end = %d\n",start,end);
        //printf("startstep = %d, endstep = %d\n",startstep,endstep);
        fprintf(fout,"%lld\n",count);
    }
    
    fclose(fin);
    fclose(fout);
    //free(solveCount);
    return 0;
}