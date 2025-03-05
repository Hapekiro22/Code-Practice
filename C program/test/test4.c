#include<stdio.h>
#define SUM 10 

void fun(char c)
{
    printf("%c",c);
}

int main()
{
    char a = 'a',b = 1;
    //b = b<<8;
    fun((int)(a+b));
}