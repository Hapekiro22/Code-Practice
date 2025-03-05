//贪心算法，但存在误差
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SUBJECT 4

int abscmp(const void *a, const void *b)
{
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    return (abs(int_a) - abs(int_b));
}

int main()
{
    /*FILE *fp2 = fopen("nnzdqzrc/nnzdqzrc3.ans","r");
    int ans;   
    fscanf(fp2,"%d",&ans); 
    printf("ans:%d\n",ans);
    fclose(fp2);*/

    FILE *fp = fopen("nnzdqzrc/nnzdqzrc0.in","r");
    int s[SUBJECT];
    int *t[SUBJECT];
    for(int i = 0;i < SUBJECT;i++)
        fscanf(fp,"%d",&s[i]);
    for(int i = 0;i < SUBJECT;i++)
    {
        t[i] = malloc(s[i] * sizeof(int));
        for(int j = 0;j < s[i];j++)
        {
            fscanf(fp,"%d",&t[i][j]);
        }
    }
    //printf("s:%d %d %d %d\n",s[0],s[1],s[2],s[3]);
    fclose(fp);
    int sum[SUBJECT] = {0};
    for(int i = 0;i < SUBJECT;i++)
    {
        for(int j = 0;j < s[i];j++)
        {
            sum[i] += t[i][j];
        }
    }
    //printf("sum:%d %d %d %d\n",sum[0],sum[1],sum[2],sum[3]);
    int sumtime = 0;
    for(int i = 0;i < SUBJECT;i++)
    {
        if(s[i] == 1)
            sumtime += t[i][0];
        else if(s[i] == 2)
            sumtime += (t[i][0] > t[i][1]?t[i][0]:t[i][1]);
        else
        {
            int half_sum = sum[i] / 2;
            //printf("half_sum:%d\n",half_sum);
            int *temp = (int *)malloc(s[i]*sizeof(int));
            int temp_sum = 0;
            int gap = half_sum - temp_sum;
            int last = 0,lastgap = 0;
            while(gap > 0)
            {
                lastgap = gap;
                for(int j = 0;j < s[i];j++)
                {
                    temp[j] = t[i][j] - gap;
                }
                qsort(temp,s[i],sizeof(int),abscmp);
                temp_sum += temp[0] + gap;
                //printf("add:%d\n",temp[0] + half_sum);
                gap = half_sum - temp_sum;
                //printf("gap:%d\n",gap);
                last = temp[0];
            }
            //printf("lastgap:%d,last:%d\n",lastgap,last);   
           //printf("half:%d,another:%d\n",(temp_sum + (count - 1)*half_sum ),(sum[i] - temp_sum - (count-1)*half_sum));
            int max1 = temp_sum > (sum[i] - temp_sum)?temp_sum:(sum[i] - temp_sum);
            int max2 = (temp_sum - last - lastgap) > (sum[i] - temp_sum + last + lastgap)?(temp_sum - last - lastgap):(sum[i] - temp_sum + last + lastgap);
            //printf("max1:%d max2:%d\n",max1,max2);
            int max = (max1 < max2)?max1:max2;
            sumtime += max;
        }
    }

    printf("output:%d\n",sumtime);

    return 0;
}
    