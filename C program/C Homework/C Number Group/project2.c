//将一个数组中两部分元素交换

#include<stdio.h>
#include<malloc.h>

void rotate(int *arr,int start,int end)       //将数组部分元素颠倒
{
    int temp;
    while(start<end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

}

void swap(int* arr,int k,int len)   //k是数组两部分的分界点
{;
    printf("%d\n",len);
    rotate(arr,0,len-1);
    rotate(arr,0,len-k-1);
    rotate(arr,len-k,len-1);

}

int main()
{
    int n,i;
    scanf("%d",&n);
    int* arr = (int*)malloc(n * sizeof(int));
    for( i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    scanf("%d",&k);

    swap(arr,k,n);

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    //free(arr);
    return 0;

}