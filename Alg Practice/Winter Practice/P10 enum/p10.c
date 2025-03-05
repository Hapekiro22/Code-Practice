//统计x再1~n中出现的次数
#include<stdio.h>
#include<math.h>

long long countnum(long n, int x)
{
    int count = 0;
    long long result = 0;
    long temp = n;
    for( ;n;n/=10,count++);
    n = temp;
    printf("n=%ld, count=%d\n", n, count);
    if(x<(n/(long)pow(10,count-1)))
        result+=pow(10,count-1);
    else if(x==n)
        result+=n%(long)pow(10,count-1)+1;
    if(n==0)
        return 0;
    //printf("result=%lld, n = %ld\n", result,n);
    result += countnum(n%(long)pow(10,count-1), x) + (n/(long)pow(10,count-1))*pow(10,count-2)*(count-1);
    return result;

}

int main()
{
    long n; int x;
    scanf("%ld %d", &n, &x);
    printf("%lld\n", countnum(n, x));
    return 0;
}