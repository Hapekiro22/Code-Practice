//素数判定

#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    if(n < 2)
        return 0;
    for(int i = 2;i <= sqrt(n);i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int s;
    scanf("%d", &s);
    int count = 0,num = 2;
    while(s>0)
    {
        if(is_prime(num))
        {
            count++;
            s-=num;
            if(s<0)
            {count--;break;}
            printf("%d\n", num);
        }
        num++;
    }
    printf("%d\n", count);
    return 0;

}