//输入一个数组，将元素颠倒排序
#include <stdio.h>
#include <stdlib.h>

void reverse(int *num,int n);

int main()
{
    int n;
    scanf("%d",&n);
    int *num = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    reverse(num,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}

void reverse(int *num,int n)
{
    int temp;
    for(int i=0;i<n/2;i++)
    {
        temp = *(num+i);
        *(num+i) = *(num+n-i-1);
        *(num+n-i-1) = temp;
    }
    return;
}