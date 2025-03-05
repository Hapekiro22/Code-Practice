//本关任务：编写一个程序replace，采用命令行的方式,用给定的字符串替换指定文件中的目标字符串，替换后保存在out.txt中。
//比如replace test1.txt you they，表示将test1.txt中的you替换为they，替换后的文件保存在out.txt中。

#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
    FILE *fp,*fp1;
    if(argc!=4)
    {
        printf("指令错误\n");
        return 0;
    }
    if((fp=fopen(argv[1],"r"))==NULL)
    {
        perror("文件打开失败");
        return 0;
    }
    if((fp1=fopen("out.txt","w"))==NULL)
    {
        perror("文件打开失败");
        return 0;
    }
    char *filename = argv[1];
    char *str1 = argv[2],*str2 = argv[3];
    char c;
    int len1 = strlen(str1),len2 = strlen(str2);
    int flag = 0;
    while((c=fgetc(fp))!=EOF)
    {
        if(c==str1[0])
        {
            flag = 1;
            for(int i=1;i<len1;i++)
            {
                if((c=fgetc(fp))!=str1[i])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                fputs(str2,fp1);
            }
            else
            {
                fputc(str1[0],fp1);
                fseek(fp,-len1+1,SEEK_CUR); 
            }
        }
    }
    fclose(fp);
    //fprintf(fp1,"\n");
    fclose(fp1);
    return 0;
}