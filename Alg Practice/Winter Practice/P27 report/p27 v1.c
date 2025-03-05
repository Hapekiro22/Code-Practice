#include <stdio.h>
#include <stdlib.h>
#define MAXHEIGHT 15000

int main()
{
    //FILE *fp = fopen("report/report17.in","r");
    long long n,b;
    scanf("%lld %lld",&n,&b);
    int *book = (int *)malloc(MAXHEIGHT*sizeof(int));
    for(int i = 0;i < MAXHEIGHT;i++)
        book[i] = 0;
    int maxh = 0;
    for(int i = 0;i < n;i++)
    {
        int height;
        scanf("%d",&height);
        book[height]++;
        if(height > maxh)
            maxh = height;
    }
    long long sumh = 0;
    long num = 0;
    for(int i = maxh;i >= 0 && sumh < b;)
    {
        if(book[i] > 0)
        {
            sumh += i;
            book[i]--;
            num++;
        }
        if(book[i] == 0)
            i--;
    }
    //printf("maxh = %d\n",maxh);
    printf("%ld\n",num);

    free(book);
    //fclose(fp);
    return 0;

}