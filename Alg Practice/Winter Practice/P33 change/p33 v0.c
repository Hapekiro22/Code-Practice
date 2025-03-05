#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct change {
    int mode;
    int series;
    double coefficient;
} change;

typedef struct dot {
    double x;
    double y;
} dot;

void changeDot(dot *dotss, change *changess)
{
    change changes = *changess;
    dot *dots = dotss;
    int mode = changes.mode;
    double k = changes.coefficient;
    //printf("choose mode = %d,coefficient = %.6lf\n",mode,k);
    if(mode == 1)
    {
        dots -> x *= k;
        dots -> y *= k;
       // printf("x = %.6lf,y = %.6lf\n",dots -> x,dots -> y);
    }
    else if(mode == 2)
    {
        double temp = dots -> x*cos(k) - dots -> y*sin(k);
        dots -> y = dots -> x*sin(k) + dots -> y*cos(k);
        dots -> x = temp;
        //printf("x = %.6lf,y = %.6lf\n",dots -> x,dots -> y);
    }
    return;
}

int main()
{
    FILE *fp = fopen("change/change1.in","r");
    FILE *fpout = fopen("change/change1.out","w");
    long n,m;
    fscanf(fp,"%ld %ld",&n,&m);
    change *changes = (change *)malloc(n*sizeof(change));
    long count1 = 0,count2 = 0;
    for(long i = 0;i < n;i++)
    {
        int mode;
        double k;
        fscanf(fp,"%d %lf",&mode,&k);
        (changes + i) -> mode = mode;
        (changes + i) -> coefficient = k;
        (changes + i) -> series = i + 1;
        if(mode == 1)   count1++;
        else count2++;
    }
    change **multiply = (change **)malloc(count1*sizeof(change *));
    change **rotate = (change **)malloc(count2*sizeof(change *));

    for(long i = 0,j = 0,k = 0;i < n;i++)
    {
        int mode = changes[i].mode;
        if(mode == 1) {multiply[j++] = &changes[i];changes[i].series = j;}
        if(mode == 2) {rotate[k++] = &changes[i];changes[i].series = k;}
    }
    //free(changes);
    double *prefixSum = (double *)malloc((count2 + 1)*sizeof(double));
    double *prefixProduct = (double *)malloc((count1 + 1)*sizeof(double));
    *prefixSum = 0;
    *prefixProduct = 1;
    for(long i = 1;i <= count1;i++)
        *(prefixProduct + i) = (*(prefixProduct + i - 1) * multiply[i - 1]->coefficient);
    for(long i = 1;i <= count2;i++)
        *(prefixSum + i) = (*(prefixSum + i - 1) + rotate[i - 1] -> coefficient);

    //for(long i = 0;i <= count1;i++)     printf("prefixProduct[%ld] = %.6lf\n",i,prefixProduct[i]);
    //for(long i = 0;i <= count2;i++)     printf("prefixSum[%ld] = %.6lf\n",i,prefixSum[i]);

    dot *dots = (dot *)malloc(m*sizeof(dot));
    for(long i = 0;i < m;i++)
    {
        long j,k,mode1,mode2;
        dot d;
        fscanf(fp,"%ld %ld %lf %lf",&j,&k,&d.x,&d.y);
        //printf("x = %.6lf,y = %.6lf\n",d.x,d.y);
        j--;k--;
        long start1 = j;
        long end1 = k;
        long start2,end2;
        for(start2 = start1;changes[start2].mode == changes[start1].mode && start2 < end1 ;start2++);
        for(end2 = end1;changes[end2].mode == changes[end1].mode && end2 > start1;end2--);
        mode1 = changes[start1].mode;mode2 = changes[end1].mode;
        //printf("In changes: start1 = %ld,start2 = %ld,end1 = %ld,end2 = %ld\n",start1,start2,end1,end2);
        start1 = changes[start1].series,start2 = changes[start2].series;
        end1 = changes[end1].series,end2 = changes[end2].series;
        double c1 = 1,c2 = 0;
        //printf("In division: start1 = %ld,start2 = %ld,end1 = %ld,end2 = %ld\n",start1,start2,end1,end2);
        //printf("mode1 = %d,mode2 = %d\n",mode1,mode2);
        if(mode1 == mode2)
        {
            if(mode1 == 1)
            {
                c1 = prefixProduct[end1] / prefixProduct[start1 - 1];
                if(start1 != end1)
                    c2 = prefixSum[end2] - prefixSum[start2 - 1];
            }
            else
            {
                if(start1 != end1)
                    c1 = prefixProduct[end2] / prefixProduct[start2 - 1];
                c2 = prefixSum[end1] - prefixSum[start1 - 1];
            }
        }
        else if(mode1 != mode2)
        {
            if(mode1 == 1)
            {
                c1 = prefixProduct[end2] / prefixProduct[start1 - 1];
                c2 = prefixSum[end1] - prefixSum[start2 - 1];
            }
            else
            {
                c1 = prefixProduct[end1] / prefixProduct[start2 - 1];
                c2 = prefixSum[end2] - prefixSum[start1 - 1];
            }
        }
        //printf("c1 = %.6lf,c2 = %.6lf\n",c1,c2);
        change change1,change2;
        change1.mode = 1,change1.coefficient = c1;
        change2.mode = 2,change2.coefficient = c2;\
        //printf("x = %.6lf,y = %.6lf\n",d.x,d.y);
        changeDot(&d,&change1);
        changeDot(&d,&change2);
        fprintf(fpout,"%.2f %.2f\n",d.x,d.y);
    }

    free(changes);
    free(multiply);
    free(rotate);
    free(prefixSum);
    free(prefixProduct);
    free(dots);
    fclose(fp);
    return 0;
}