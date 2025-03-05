#include <stdio.h>
#include <math.h>

// 统计 x 在 1~n 中出现的次数
long long countnum(long n, int x)
{
    if (n < 0) return 0; // 处理负数情况
    if (n == 0) return (x == 0) ? 1 : 0; // 处理 n 为 0 的情况

    int count = 0;
    long long result = 0;
    long temp = n;
    for (; n; n /= 10, count++);
    n = temp;

    for (int i = 0; i < count; i++)
    {
        long long a = n / (long)pow(10, count - i - 1);
        long long b = n % (long)pow(10, count - i - 1);
        //printf("a = %lld, b = %lld\n", a, b);
        //printf("count = %d, i = %d\n", count, i);

        if (x < a && x != 0)
            result += pow(10, count - i - 1);
        else if (x == a)
            result += b + 1;

        if (x == 0 && i > 0)
            result += (a - 1) * pow(10, count - i - 1);
        else
            result += a * pow(10, count - i - 2) * (count - i - 1);

        n = b;
    }

    return result;
}

int main()
{
    long n;
    int x;
    scanf("%ld %d", &n, &x);
    printf("%lld\n", countnum(n, x));
    return 0;
}