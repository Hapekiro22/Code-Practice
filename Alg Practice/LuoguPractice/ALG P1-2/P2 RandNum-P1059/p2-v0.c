#include <stdio.h>
#include <stdlib.h>
#define N 2000

int main()
{
    int count = 0;
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * N);
    for(int i = 0;i < N;i++)
    {
        arr[i] = 0;
    }

    for(int i = 0;i < n;i++)
    {
        int temp;
        scanf("%d",&temp);
        arr[temp] += 1;
        if(arr[temp] == 1)
        {
            count++;
        }
    }

    printf("%d\n", count);
    for(int i = 0;i < N;i++)
    {
        if(arr[i])
        {
            printf("%d ", i);
        }
    }

    free(arr);
    return 0;

}