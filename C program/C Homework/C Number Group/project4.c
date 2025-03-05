//将字符串s的前n个字符复制到字符串t中

#include<stdio.h>

void mystrcpy(char *s,char *t,int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        t[i] = s[i];
    }
    t[i] = '\0';
}


