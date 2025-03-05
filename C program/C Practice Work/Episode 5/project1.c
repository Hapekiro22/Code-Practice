#include <stdio.h>
#include<string.h>

void strdelc(char t[], char c);
void strcate(char t[], char s[]);

int main(void) {
    char a[10000] , b[10000], c;
    scanf("%s",b);
    scanf("%s",a);
    scanf("%c",&c);
    //printf("%s %s\n", b, a);
    strcate(b, a);
    //printf("%c\n",b[14]);
    printf("%s\n",b);
    scanf("%c",&c);
    strdelc(b, c);
    printf("%s", b);
    return 0;
}

void strcate(char t[], char s[]) 
{
    int i = 0, j = 0;
    while(t[i++]);
    i--;
    while((t[i++] = s[j++])!='\0');
}

void strdelc(char s[], char c) 	
{
    int j,k;
    for(j=k=0;s[j]!='\0';j++)
    {
        if(s[j]!=c) s[k++] = s[j];
    }
    //s[k] = '\0';
}
