//动态规划
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

int closestSubsetSum(int *arr, int n, int target);

int main()
{
    /*FILE *fp2 = fopen("nnzdqzrc/nnzdqzrc7.ans","r");
    int ans;   
    fscanf(fp2,"%d",&ans); 
    printf("ans:%d\n",ans);
    fclose(fp2);*/

    //FILE *fp = fopen("nnzdqzrc/nnzdqzrc7.in","r");
    int s[SUBJECT];
    int *t[SUBJECT];
    for(int i = 0;i < SUBJECT;i++)
        scanf("%d",&s[i]);
    for(int i = 0;i < SUBJECT;i++)
    {
        t[i] = malloc(s[i] * sizeof(int));
        for(int j = 0;j < s[i];j++)
        {
            scanf("%d",&t[i][j]);
        }
    }
    //printf("s:%d %d %d %d\n",s[0],s[1],s[2],s[3]);
    //fclose(fp);
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
            int target = closestSubsetSum(t[i],s[i],sum[i]/2);
            if(target < sum[i] - target)
                sumtime += sum[i] - target;
            else
                sumtime += target;
        }
    }

    printf("%d\n",sumtime);

    return 0;
}

int closestSubsetSum(int *arr, int n, int target)
{
    int *dp = (int *)malloc((target + 1) * sizeof(int));
    for(int i = 0;i < target + 1;i++)
        dp[i] = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = target;j >= arr[i];j--)
        {
            dp[j] = dp[j] > dp[j - arr[i]] + arr[i]?dp[j]:dp[j - arr[i]] + arr[i];
        }
    }
    return dp[target];
}
    