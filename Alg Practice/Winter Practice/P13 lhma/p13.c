//0-1压缩后矩阵展开
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,flag = 0,i = 0;
    scanf("%d",&n);
    int *Matrix = (int *)malloc(n*n*sizeof(int));
    int c,sum = 0;
    while(scanf("%d",&c)!=EOF)
    {
        sum+=c;
        int num = c;
        for(int j = 0;j < num;j++,Matrix[i++] = flag);
        flag = (flag + 1)%2;
        if(sum == n*n)
            break;
    }
    for(i = 0;i < n*n;i++)
    {
        printf("%d ",Matrix[i]);
        if((i%n)==n-1)
            printf("\n");
    }
    return 0;
}
