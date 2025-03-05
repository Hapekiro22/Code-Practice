//用冒泡排序将数组升序排序

#include <stdio.h>
#include <string.h>

void selectSort(int *arr,int len)
{
    int i,len,j,temp;
    //len = sizeof(arr)/sizeof(arr[0]);

    for(i = 0;i < len;i++)
    {
        for(j = i+1;j< len;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void inArray(int *arr,int len)
{
    for(int i = 0;i < len;i++)
    {
        scanf("%d ",&arr[i]);
    }
}

void outArray(int *arr,int len)
{
    for(int i = 0;i < len;i++)
    {
        printf("%d ",arr[i]);
    }
}