//去掉有序整数列中的重复元素，返回去重后的序列长处长度
#include <stdio.h>
#include <stdlib.h>

int RemoveSame(int *a, int n)
{
    int *check = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        check[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] == a[j])
            {
                check[j] = 1;
            }
        }
    }

    int len=0;
    for(int i = 0; i < n; i++)
    {
        if(check[i] == 0)
        {
            len++;
            if(i == n - 1)
                printf("%d", a[i]);
            else
            printf("%d ", a[i]);
        }
    }
    return len;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int len = RemoveSame(a, n);
    printf("\n%d", len);
    return 0;
}