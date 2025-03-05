//找出一串数字中第k个小的数
//将输入的数字存入一个数组之中，依序读取即可
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int *arr = (int *)malloc(30000*sizeof(int));
    for(int i = 0;i < 30000;i++)
        *(arr + i) = 0;
    for(int i = 0;i < n;i++)
    {
        int num;
        scanf("%d",&num);
        *(arr + num) = num;
    }
    int count = 0,i;
    for(i = 0;i < 30000 && count < k;i++)
    {   
        if(*(arr+i))
            count++;
    }
    if(count < k)
        printf("NO RESULT\n");
    else
        printf("%d\n",i-1);

    free(arr);
    return 0;

}