#include<stdio.h>

int main()
{
    unsigned short x=1,y=2,z=4,mask=0xc3,w;
    short v;

    x+=y+=1+2;
    printf("%hu",x);
}