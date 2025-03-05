//设计一个字段结构，将一个8位无符号字节从最低位向最高位声明为8个字段
//bit0,bit1,bit2,bit3,bit4,bit5,bit6,bit7，bit0优先级最高，bit7优先级最低。
//设计8个函数，以bitn为参数
//用一个函数指针数组存放这8个函数的地址，如果bit0=1，就调用第一个函数
//若结构中有多个1，就根据优先级从高到低依次调用这些函数

#include <stdio.h>
#include <stdlib.h>

typedef struct bits
{
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char bit2:1;
    unsigned char bit3:1;
    unsigned char bit4:1;
    unsigned char bit5:1;
    unsigned char bit6:1;
    unsigned char bit7:1;

}bits;

void f0(int b)
{
    printf("the function %d is called!\n", b);
}

void f1(int b)
{
    printf("the function %d is called!\n", b);
}

void f2(int b)
{
    printf("the function %d is called!\n", b);
}

void f3(int b)
{
    printf("the function %d is called!\n", b);
}

void f4(int b)
{
    printf("the function %d is called!\n", b);
}

void f5(int b)
{
    printf("the function %d is called!\n", b);
}

void f6(int b)
{
    printf("the function %d is called!\n", b);
}

void f7(int b)
{
    printf("the function %d is called!\n", b);
}

int main()
{
    int num;
    scanf("%d", &num);
    num = (char)num;
    //先将num的8个字节取出来
    bits *p = (bits *)&num;
    void (*f[8])(int) = {f0, f1, f2, f3, f4, f5, f6, f7};
    if(p->bit0)
    {
        f[0](0);
    }
    if(p->bit1)
    {
        f[1](1);
    }
    if(p->bit2)
    {
        f[2](2);
    }
    if(p->bit3)
    {
        f[3](3);
    }
    if(p->bit4)
    {
        f[4](4);
    }
    if(p->bit5)
    {
        f[5](5);
    }
    if(p->bit6)
    {
        f[6](6);
    }
    if(p->bit7)
    {
        f[7](7);
    }

    return 0;
}