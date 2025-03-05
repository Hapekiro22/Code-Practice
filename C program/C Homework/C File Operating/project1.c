//使用type_c指令读取指定c程序的全部内容，并为每一行开头加上行号
// type_c指令的使用方法为：type_c 文件名
//使用type_c /p 指令读取指定c程序的全部内容，并为每一行开头加上行号,并且每10行显示一屏，输入q后显示下一屏
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char c,chq;
    int row = 1, count = 0,mode,page=0;
    char filename[100],command[200],filepath[200];
    const char *folder = "D:\\C C++\\C Project\\C program\\C Homework\\C Struct\\";
    printf("请输入文件名：");
    fgets(command,sizeof(command),stdin);
    if(strncmp(command,"type_c",6)!=0)
    {
        printf("指令错误\n");
        return 0;
    }
    if(strncmp(command,"type_c /p",9)==0)
    {
        mode=1;
        sscanf(command,"%*s %*s %s",filename);//读取文件名,忽略前两个字符串
    }
    else
    {
        mode=0;
        sscanf(command,"%*s %s",filename);
    }
    snprintf(filepath,sizeof(filepath),"%s%s",folder,filename);
    printf("文件路径：%s\n",filepath);
    if((fp=fopen(filepath,"r"))==NULL)
    {
        perror("文件打开失败");
        printf("文件打开失败\n");
        return 0;
    }
    if(mode==0)
    {
        while((c=fgetc(fp))!=EOF)
        {
            if(count==0)
                printf("%d ",row++);
            putchar(c);
            if(c=='\n')
                count=0;
            else
                count++;
        }
    }
    if(mode==1)
    {
        while((c=fgetc(fp))!=EOF)
        {
            if(count==0)
                printf("%d  ",row);
            putchar(c);
            if(c=='\n')
                {count=0; row++;}
            else
                count++;
            if(row==11)
            {
                //printf("输入q显示下一页，输入其他字符退出\n");
                chq=getchar();
                if(chq=='q')
                {
                    page++;
                    row = 1;
                }
            }

        }
    }
    fclose(fp);
    return 0;
    
}