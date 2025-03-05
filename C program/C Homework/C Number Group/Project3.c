//统计各数字，英文字母还有其他字符出现的次数

#include <stdio.h>

void count(char *str)
{
    char character[256] = {0};
    int i,j=0;

    for(i = 0;i < 10000; i++)
    {
        if(str[i] == '\n')
        {
            break;
        }
        character[str[i]]++;
    }

//打印各个字符的个数
    for (i = 0; i < 256; i++)
    {
        if (character[i] != 0)
        {
            if (i >= '0' && i <= '9')
            {
                printf("数字%c出现%d次\n", i, character[i]);
            }
            else if (i >= 'a' && i <= 'z')
            {
                printf("小写字母%c出现%d次\n", i, character[i]);
            }
            else if (i >= 'A' && i <= 'Z')
            {
                printf("大写字母%c出现%d次\n", i, character[i]);
            }
            else
            {
                j+=character[i];
                printf("其他字符%d出现%d次\n", i, character[i]);
            }
        }
    }
    printf("其他字符出现%d次\n", j);
}

int main()
{
    char str[10000]={0};
    int i=0;
    while((str[i]=getchar())!='\n')
    {
        i++;
    }
    count(str);
    return 0;
}