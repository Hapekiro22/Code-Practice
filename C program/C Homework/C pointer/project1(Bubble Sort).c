 //冒泡升序排序 ，程序的输入为 int类型数组 和数组长度 
#include <stdio.h>
#include <stdlib.h>

void bubblesort(int *num,int n);

int main()
{
    int n;
    scanf("%d",&n);
    int *num = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    bubblesort(num,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }
    return 0;
}

void bubblesort(int *num,int n)
{
    int temp,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(*(num+i)>*(num+j))
            {
                temp = *(num+i);
                *(num+i) = *(num+j);
                *(num+j) = temp;
            }
        }
    }
    return;
}