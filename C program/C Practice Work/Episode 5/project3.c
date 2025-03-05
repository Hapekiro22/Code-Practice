#include <stdio.h>
#include <string.h>

// 类似数字统计，用字符的ASCII码作为下标，统计每个字符出现的次数
void RemoveDuplicate(char *str)
{
    int sign[256] = {0}; // 初始化为0
    int len = strlen(str), count;

    int w = 0;
    for(count = 0; count < len; count++)
    {
        if(sign[(int)str[count]] == 0) // 第一次出现的字符
        {
            str[w++] = str[count];
            sign[(int)str[count]] = 1; // 标记为已出现，一边统计一边读取，提高效率
        }
    }
    str[w] = '\0'; // 终止字符串
}


int main()
{
    char str[1000];
    scanf("%s", str);
    RemoveDuplicate(str);
    printf("%s", str);
    return 0;
}


/*
//simplified project2
#include<stdio.h>
#include<string.h>

void RemoveDuplicate(char *str);

int main()
{
    char str[1000];
    scanf("%s",str);
    RemoveDuplicate(str);
    printf("%s",str);
    return 0;
}

void RemoveDuplicate(char *str)
{
    int sign[256] = {1};
    int len = strlen(str),count;

    for(count = 0;count < len;count++)
    {
        if(sign[(int)(str[count])]!=1)
        {
            sign[(int)(str[count])] = 0;
        }
        else sign[(int)(str[count])]++;
    } 

    int j = 0,w = 0;
    while(j<len)
    {
        if((sign[(int)str[j]]==0))
        {
            str[w++] = str[j];
            sign[(int)str[j]]+=2;
        }
        if((sign[(int)str[j]]==1))
        {
            str[w++] = str[j];
        }
        //if(sign[(int)str[j]]==2)
        j++;

    } 
    str[w] = '\0';


}
*/