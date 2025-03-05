//高精度等比数列求和
#define STEPLONG 2
#define RATE 0.98
#include<stdio.h>

int main()
{
    double distance;
    scanf("%lf",&distance);
    double sum = 0,step = 0;
    double steplong = STEPLONG;
    while(sum < distance)
    {
        step++;   
        sum += steplong;
        steplong *= RATE;
    }
    printf("%.0lf\n",step);
    return 0;
}