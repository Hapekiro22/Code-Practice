#include<stdio.h>

int main()
{
    int num1,num2,sum;
    char c;
    scanf("%d %d %c",&num1,&num2,&c);

    if(c=='+')
    {
        sum = num1 + num2;
    }

    if(c=='-')
    {
        sum = num1 - num2;
    }

    if(c=='*')
    {
        sum = num1 * num2;
    }

    if(c=='/')
    {
        sum = (float)(num1 / num2);
    }

    printf("%d %d ",num1,num2);
    printf("%.1f",(float)sum);

    return 0;



}

