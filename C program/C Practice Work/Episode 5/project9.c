//将字符串s插入字符串t的第n个字符后
#include<stdio.h>
#include<malloc.h>
#include<string.h>

void insertString(char *t,char *s,int n);

int main()
{
    int n;
    char *t = malloc(1000), *s = malloc(1000);
    scanf("%s",t);
    scanf("%s",s);
    scanf("%d",&n);
    insertString(t,s,n);
    printf("%s\n",t);
    return 0;
}

void insertString(char *t,char *s,int n)
{
    int i = strlen(s)-1;
    while(i>=0)         //将t的第n个字符后的字符后移s的长度
    {
        char temp;
        temp = t[n+i];
        t[n+i] = '\0';
        t[n+i+strlen(s)] = temp;
        i--;
    }
    for(i=0;i<strlen(s);i++)    //将s插入t的第n个字符后
    {
        t[n+i] = s[i];
    }
}

