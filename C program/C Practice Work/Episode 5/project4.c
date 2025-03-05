#include <stdio.h>
#define M 10
#define N 3

int main(void)
{
    int m,n;
    scanf("%d %d",&m,&n);
    int a[M], b[M];
    int i, j, k;
    for (i = 0; i < m; i++)
        a[i] = i + 1;
    for (i = m, j = 0; i > 1; i--)
    {
        for (k = 1; k <= n; k++)
            if (++j >= i)
                j = 0;
        b[m - i] = j ? a[j - 1] : a[i - 1];
        if (j)
            for (k = --j; k < i - 1; k++)
                a[k] = a[k + 1];
    }
    //b[m - 1] = a[0];
    for (i = 0; i < m-1; i++)
        printf("%6d", b[i]);
    printf("\n%6d",a[0]);
    return 0;
}