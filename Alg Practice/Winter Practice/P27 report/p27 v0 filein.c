//动态规划
#include <stdio.h>
#include <stdlib.h>

void closestSubsetSum(int *arr, int n, int target);

int main()
{
    FILE *fp = fopen("report/report0.in","r");
    long long n,b;
    fscanf(fp,"%lld%lld",&n,&b);
    int *a = malloc(n * sizeof(int));
    for(int i = 0;i < n;i++)
        fscanf(fp,"%d",&a[i]);
    closestSubsetSum(a,n,b);
    free(a);
    return 0;
}

void closestSubsetSum(int *arr,int n,int target)
{
    int *dp = (int *)malloc((target + 1) * sizeof(int));
    int *num = (int *)malloc((target + 1) * sizeof(int));
    for(int i = 0;i < target + 1;i++)
    {
        dp[i] = 0;
        num[i] = 0;
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = target;j >= arr[i];j--)
        {
            if(dp[j] <= dp[j - arr[i]] + arr[i])
            {
                dp[j] = dp[j - arr[i]] + arr[i];
                num[j] = num[j - arr[i]] + 1;
            }
        }
    }
    //printf("%d\n",dp[target]);
    if(dp[target] < target)
        printf("%d\n",num[target] + 1);
    else
        printf("%d\n",num[target]);

    free(dp);
    return;
}