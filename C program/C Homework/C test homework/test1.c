#include<stdio.h>

int main()
{
    int a=1,b=2,c=3,d,n;
    double x=2.0,y=7.7;
    float m;
    n=(a=0,--a,a+=(a++)-a);
    printf("%d\n",n);
    //printf("%f\n",);

    return 0;
}