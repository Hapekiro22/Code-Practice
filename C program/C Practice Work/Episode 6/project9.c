//对n个整数排序，元素个数由命令行参数指定，排序方法由命令行可选参数决定，由-d的时候降序排序，否则升序排序
//比如在命令行输入sort 10 -d，然后在main函数中输入10个整数排序
//n是一个命令行参数，表示输入的整数个数
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int *a = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if(argc == 3 && argv[2][0] == '-' && argv[2][1] == 'd')
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(a[j] < a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(a[j] > a[j + 1])
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
    }

    for(int i = 0; i < n; i++)
    {   
        if(i == n - 1)
            printf("%d", a[i]);
        else
        printf("%d ", a[i]);
    }

}