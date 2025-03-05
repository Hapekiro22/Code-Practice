//计算数n所处的2的幂次方区间
#include <stdio.h>
#include <math.h>

int main()
{
    long long n;
    scanf("%lld", &n);
    int count = 0;
    while(n)
    {
        n >>= 1;
        count++;
    }
    printf("%d\n", count);
    return 0;
}