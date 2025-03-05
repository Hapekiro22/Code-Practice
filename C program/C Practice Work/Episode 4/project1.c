//记忆递归函数
#include<stdio.h>

long long Fib[10000];

long long Fibonacci(int n)
{
    if((n==1)||(n==2))
    {
        Fib[n-1] = 1;
        return 1;
    }
    Fib[n-1] = Fibonacci(n-1) + Fib[n-3];
    return Fib[n-1];
}

int main()
{
    int n;
    scanf("%d",&n);
    int sum;

    sum = Fibonacci(n+1);
    printf("%lld",sum);

    return 0;

}