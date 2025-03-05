//实现文件内容的链接，将file1，file2，file3的内容链接到file中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void connect(char *filename,char *filename1,char *filename2,char *filename3)
{
    FILE *fp,*fp1,*fp2,*fp3;
    char c;
    if((fp=fopen(filename,"w"))==NULL)
    {
        perror("文件打开失败");
        return;
    }
    if((fp1=fopen(filename1,"r"))==NULL)
    {
        perror("文件打开失败");
        return;
    }
    if((fp2=fopen(filename2,"r"))==NULL)
    {
        perror("文件打开失败");
        return;
    }
    if((fp3=fopen(filename3,"r"))==NULL)
    {
        perror("文件打开失败");
        return;
    }
    while((c=fgetc(fp1))!=EOF)
    {
        fputc(c,fp);
    }
    while((c=fgetc(fp2))!=EOF)
    {
        fputc(c,fp);
    }
    while((c=fgetc(fp3))!=EOF)
    {
        fputc(c,fp);
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}    