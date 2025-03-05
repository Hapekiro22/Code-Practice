//hash:n -> n
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long n,m;
    scanf("%ld %ld",&n,&m);
    long *votes = (long *)malloc(n *sizeof(long));
    for (long i = 0; i < n; i++)
    {
        votes[i] = 0;
    }

    for(int i = 0;i < m;i++)
    {
        long num;
        scanf("%ld",&num);
        votes[num - 1]++;
    }

    for(int i = 0;i < n;i++)
    {
        while(votes[i]--)
        {
            printf("%d ",i + 1);
        }
    }
    return 0;
}