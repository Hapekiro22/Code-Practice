//给出现有钱数，计算可购买的最大数量的商品

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int sum = a*10 + b;
    int result = sum/19;
    printf("%d\n",result);
    return 0;
}