#include <stdio.h>
#include <stdlib.h>
#define LIMIT 250000

int main()
{
    FILE *fin = fopen("binary/binary10.in","r");
    FILE *fout = fopen("binary/binary10.out","w");
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
    long x,y;
    for(long i = 0;i < m;i++)
    {
        int mode;
        fscanf(fin,"%d",&mode);
        switch(mode)
        {
            case 1:
                fscanf(fin,"%ld",&x);
                *(result + i) = *(num + x + LIMIT);
                break;
            case 2:
                fscanf(fin,"%ld %ld",&x,&y);
                for(long j = x + LIMIT;j <= y + LIMIT;j++)
                    *(result + i) += *(num + j);
                break;
            case 3:
                fscanf(fin,"%ld %ld",&x,&y);
                for(long j = x + LIMIT;j < y + LIMIT;j++)
                    *(result + i) += *(num + j);
                break;
            case 4:
                fscanf(fin,"%ld %ld",&x,&y);
                for(long j = x + LIMIT + 1;j <= y + LIMIT;j++)
                    *(result + i) += *(num + j);
                break;
            case 5:
                fscanf(fin,"%ld %ld",&x,&y);
                for(long j = x + LIMIT + 1;j < y + LIMIT;j++)
                    *(result + i) += *(num + j);
                break;
            default:
        }
    }

    for(long i = 0;i < m;i++)
    {
        fprintf(fout,"%ld\n",*(result + i));
    }

    free(num);
    free(result);

    fclose(fin);
    fclose(fout);
    return 0;
}