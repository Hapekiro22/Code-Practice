#include<stdio.h>
int main(void)
{
    char c, numchar, numline;
    numchar = 0;
    numline = 0;
    printf("�����������ı�����������Ctrl+z������\n");
    while((c = getchar() )!= EOF)
	{
        numchar++;
        if(c == '\n')
            numline++;
    }
    printf("�ַ���:%d,", numchar - 1);
    printf("����:%d", numline);
    return 0;
}
