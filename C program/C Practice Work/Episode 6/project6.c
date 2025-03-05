//将一个整型数用指针取出每一个字节高四位和低四位的数，由高到低，用十六进制打印出来
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d", &num);
    int *p = &num;
    char *q = (char *)p+3;
    int masklow = (1 << 4) - 1;
    int maskhigh = masklow << 4;
    for (int i = 0; i < 4; i++)
    {
        printf("%X ", (*q & maskhigh) >> 4);
        printf("%X ", *q & masklow);
        q--;
    }
    return 0;
}