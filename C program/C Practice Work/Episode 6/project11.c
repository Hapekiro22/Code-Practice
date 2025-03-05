//计算两个位数不超过200位的非负整数乘积
#include<stdio.h>
#include<stdlib.h>

int* multiplenum(int *a,int *b);
int* singlemultiple(int *a,int num);
int* plusnum(int *a,int *b);
int* move(int *num,int n);
void getnum(int *num);
void printnum(int *num);

int main()
{
    int a[4000],b[4000];
    int *num = NULL;
    printf("Please input the first number:\n");
    getnum(a);
    printf("Please input the second number:\n");
    getnum(b);
    num = multiplenum(a,b);
    printf("The multiplied result is:\n");
    printnum(num);
    free(num);
    return 0;
}

int *multiplenum(int *a,int *b)
{
    int *num = (int *)malloc(4000*sizeof(int));
    for(int i = 0;i<4000;i++) *(num+i) = 0;                      //初始化num数组,存储乘积结果

    int *multednum = NULL;
    for(int i = 3999;i >=3800 ;i--)
    {
        int multnum = b[i];                                     //取b数组的一个数,从低位开始
       // printf("Multiplying with b[%d] = %d\n", i, multnum);  // 调试信息
        multednum = singlemultiple(a,multnum);                  //将a数组与这个数相乘
        multednum = move(multednum,3999-i);                     //将乘积结果向左移动i位
        num = plusnum(num,multednum);                           //将乘积结果与num数组相加
    }

    free(multednum);

    return num;
}

int *singlemultiple(int *a,int num)
{
    int *multednum = (int *)malloc(4000*sizeof(int));
    for(int i = 0;i<4000;i++) *(multednum+i) = 0;
    int singlemult,upper=0;
    for(int i = 3999;i>=0;i--)
    {
        singlemult = (*(a+i)) * num + upper;
        *(multednum+i) = singlemult%10;                           //取个位数,upper是上一次的进位
        upper = singlemult/10;                                    //计算进位，下一次循环使用
    }
    return multednum;
}

int *plusnum(int*a,int*b)
{
    int *sum = (int*)malloc(4000*sizeof(int));
    for(int i = 0;i<4000;i++) *(sum+i) = 0;
    int upper = 0, singleplus;
    for(int i = 3999;i>0;i--)
    {
        singleplus = *(a+i) + *(b+i) + upper;
        *(sum+i) = singleplus%10;
        upper = singleplus/10;
    }
    return sum;
}

void getnum(int *num)                     //将输入的数字转换为数组,存储在数组高位中（如0000123）
{
    for(int i = 0;i<4000;i++) *(num+i) = 0;
    char c;
    int i = 3999;
    while((c = getchar()) != '\n')
    {
        *(num+i) = c - '0';
        i--;
    }
    int start = i + 1;
    int end = 3999;
    while(start < end) 
    {
        int temp = *(num+start);
        *(num+start) = *(num+end);
        *(num+end) = temp;
        start++;
        end--;
    }
}

void printnum(int *num)
{
    int i = 0;
    while(*(num+i) == 0) i++;
    for(;i<4000;i++) printf("%d",*(num+i));
    printf("\n");
}

int *move(int *num,int n)                           //将数组num向左移动n位
{
    int *movednum = (int *)malloc(4000*sizeof(int));
    for(int i = 0;i<4000;i++) *(movednum+i) = 0;
    for(int i = 0;i<4000-n;i++) *(movednum+i) = *(num+i+n);
    return movednum;
}