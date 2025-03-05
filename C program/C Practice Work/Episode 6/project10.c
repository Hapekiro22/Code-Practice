//删除一段字符串的某一字串，如果没有该字串，返回0，否则返回1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Delsubstr(char *str, char *sub);

int main()
{
    char str[1000], sub[1000];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = '\0';
    int result = Delsubstr(str, sub);
    if(result)  
        {printf("%s", str);
        printf("\n");
        printf("%d", result);}
    else 
    {
        printf("%s\n", str);
        printf("%d", result);
    }
    return 0;
}

int Delsubstr(char *str,char *sub)
{
    char *p = strstr(str, sub);
    int count = 0;
    int len = strlen(sub);
    if(p==NULL) return 0;
    int lens = strlen(p);
    while(p!=NULL)                  //如果找到了子串, 给字串的每个字符赋值为1作为标记
    {
        for(int i=0;i<len;i++)
        {
            *(p+i) = 1;
        }
        p = strstr(str, sub);
        count++;
    }
    if(count == 0)
        return 0;
    int j=0;
    for(int i=0;i<=strlen(str);i++)  //将标记的字符删除
    {
        if (str[i] != 1)
        {
            str[j++] = str[i];
        }
        i++;
    }
    
    if(count)
        return 1;
}
