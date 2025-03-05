//实现单精度浮点数的读写
//从键盘输入10个单精度浮点数，以二进制形式存入文件float.dat中（将此功能定义成函数）。再从文件中读出这10个单精度浮点数,把每个单精度浮点数，按每个字节的二进制形式显示在屏幕上（将此功能定义成函数）

#include<stdio.h>
#include<string.h>

void write_float()
{
    FILE *fp;
    if((fp=fopen("float.dat","wb"))==NULL)
    {
        perror("文件打开失败");
        return;
    }
    float f;
    for(int i=0;i<10;i++)
    {
        scanf("%f,",&f);
        fwrite(&f,sizeof(float),1,fp);
    }
    fclose(fp);
}

void read_float()
{
    FILE *fp;
    if((fp=fopen("float.dat","rb"))==NULL)
    {
        perror("文件打开失败");
        return;
    }
    float f;
    for(int i=0;i<10;i++)
    {
        fread(&f,sizeof(float),1,fp);
        unsigned char *p = (unsigned char *)&f;
        for(int j=sizeof(float)-1;j>=0;j--)
        {
            for(int k=7;k>=0;k--)
            {
                printf("%d",p[j]>>k&1);
            }
            //printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    write_float();
    read_float();
    return 0;
}