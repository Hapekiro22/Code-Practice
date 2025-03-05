#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

long num,count;

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n <= 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    return 1;
}

long ChooseNum(long *arr,int n,int k)
{
    if(k == 0)
        return 0;
    for(int i = 0;i < n;i++)
    {
        long sum = 0;
        printf("arr[%d] = %ld ",i,arr[i]);
        if(arr[i] != 0)
        {
            sum += arr[i];
            arr[i] = 0;
            sum += ChooseNum(arr,n,k - 1);
        }
        printf("sum: %ld\n",sum);
        if(n == num && isPrime(sum))
        {
            count++;
            printf("sum: %ld\n",sum);
        }
        return sum;
    }
}

int main()
{
    int k;
    scanf("%d %d", &num, &k);
    long *arr = (long *)malloc(num * sizeof(long));
    for(int i = 0; i < num;i++)
    {
        scanf("%ld", &arr[i]);
    }
    ChooseNum(arr,num,k);
    printf("%ld", count);
    free(arr);
    return 0;
}