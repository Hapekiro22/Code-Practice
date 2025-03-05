#include<stdio.h>
#include<stdlib.h>

typedef struct character
{
    short c1: 5;
    short c2: 5;
    short c3: 6;
}character;

int main()
{
    character c;
    c.c1 = 1;
    c.c2 = 244;
    c.c3 = 16;
    printf("%x %x %x\n", c.c1, c.c2, c.c3);
    return 0;
}