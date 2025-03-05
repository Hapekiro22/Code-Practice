#include<stdio.h>

int main()
{
    double e;
    scanf("%lf",&e);

    double n = 1.0000000000;
    double pi = 0;
    while((1/n)>e);
    {
        pi = pi + (1/n);
        n = 2*n + 1;
    }

    printf("%.6lf",pi);

    return 0;
    
}
