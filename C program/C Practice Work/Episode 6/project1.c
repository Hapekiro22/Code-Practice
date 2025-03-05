//字符串s赋值给t
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s1[100], s2[100], *s3=NULL;
    scanf("%s", s2);
    strcpy(s1,s2);
    printf("%s",s1);
    scanf("%s", s2);
    s3 = strcpy(s1, s2);
    printf("%s\n", s3);
    return 0;
}

/* 将字符串 s 复制给字符串 t, 并且返回串 t 的首地址 */
char *strcpy(char *t, const char *s)
{
    char *p = t;
    while((*t++ = *s++) != '\0');
    return p;
}