//计算加权平均成绩
#include<stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int result = (a*0.2 + b*0.3 + c*0.5);
    printf("%d\n",result);
    return 0;
}