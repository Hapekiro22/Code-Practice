#define CHANGE 1
#include<stdio.h>

int main(void)
{
    char c;
    #ifdef CHANGE==1
       while((c = getchar())!=EOF)
       {
           if((c>='a')&&(c<='z'))
           {
               c = c - 'a' + 'A';
           }
           else if((c>='A')&&(c<='Z'))
           {
               c = c - 'A' + 'a';
           }
           putchar(c);
       }
    #endif

   #ifdef CHANGE==0
       while((c=getchar())!=EOF)
       {
            putchar(c);
       }
    #endif
    
    return 0;
}