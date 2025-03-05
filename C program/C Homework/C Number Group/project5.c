//十六进制数字转换为十进制数字

#include<stdio.h>
#include<string.h>

void Convert(char *str)
{
    int i = 0 ,len = strlen(str),multiple,sum = 0;
    while(str[i]!='\0')
    {
        multiple = (1<<(4*(len-i-1)));
        if(str[i]>='0'&&str[i]<='9')
        {
            sum += (str[i]-'0')*multiple;
        }
        else if(str[i]>='A'&&str[i]<='F')
        {
            sum += (str[i]-'A'+10)*multiple;
        }
        else if(str[i]>='a'&&str[i]<='f')
        {
            sum += (str[i]-'a'+10)*multiple;
        }
        i++;
    }
}