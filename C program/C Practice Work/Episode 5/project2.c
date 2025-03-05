//去重字符函数
//双重指针用法，对数组覆写！！

#include<stdio.h>
#include<string.h>

void RemoveDuplicate();

int main()
{
	char str[200];
    printf("Input strings, end of Ctrl+z\n");
    while(fgets(str, 200, stdin) != NULL)
     {
   		RemoveDuplicate(str);
        printf("%s", str);
     }
    return 0;
}

void RemoveDuplicate(char *s)
{
   int r,  i, len;
   int w;
   len = strlen(s);
   for (r = w = 0; r < len; r++)
   {
   		if(s[r]!='\0')
      {
      	   s[w++] = s[r];
           for (i = r + 1; i < len; i++)
           {
         	   if(s[i]==s[r])
            	   s[i] = '\0';
           }
      }
       
   }
   s[w] = '\0';
}