#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{      
    //定义一个函数指针数组，用于指向不同的函数
    char* (*p[3])(char*,const char*) = {strcpy,strcat,strtok};
    char a[80],b[80],*result;
    int choice;
    while(1)
    {
        do
        {
            scanf("%d",&choice);
        }
        while(choice<1||choice>4);
        if(choice==4)
            goto down;
        getchar();
        //printf("请输入字符串a：\n");
        fgets(a, sizeof(a), stdin);
        a[strcspn(a, "\n")] = '\0'; // 去除换行符
        //printf("请输入字符串b：\n");
        fgets(b, sizeof(b), stdin);
        b[strcspn(b, "\n")] = '\0';
        result = (*p[choice-1])(a,b);
        printf("%s\n",result);
    }
    down: return 0;

}