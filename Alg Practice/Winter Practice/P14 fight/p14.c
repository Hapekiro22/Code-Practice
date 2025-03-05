#include<stdio.h>
#include<stdlib.h>
#define MAX 100000000000

long long llabs(long long a)
{
    return a < 0 ? -a : a;
}

long long calculateSoilder(long long *arr,int n,int m)  
{
    //统计双方士气差，规定士气为正是A（左方），反之为B（右方）
    long long result = 0;
    int i = 0;
    for(;i < n;i++)
        result += (m-i)*arr[i];
    return result;
}

int main()
{
    long n,m,p1,p2;
    long long s1,s2;
    scanf("%ld",&n);
    long long *arr = malloc(n*sizeof(long long));           //各战场士兵数
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    scanf("%ld %ld %lld %lld",&m,&p1,&s1,&s2);
    p1--,m--;
    arr[p1] += s1;
    long long originResult = calculateSoilder(arr,n,m);
    //printf("The original result is %lld\n",originResult);
    long long finalResult = originResult;
    if(originResult >= 0)                                   //目前A方占优
    {
        long fieldResult = m;
        for(long i = m;i < n;i++)
        {
            long long change = s2*(m-i);
            long long tempResult = originResult + change;
            //printf("The temp result is %lld\n",tempResult);
            if(llabs(tempResult) < llabs(finalResult))
            {
                finalResult = tempResult;
                fieldResult = i;
                //printf("Find field %d is better\n",i);
            }
        }
        printf("%ld\n",fieldResult+1);
    }
    else                                                    //目前B方占优
    {
        long fieldResult = m;
        for(long i = 0;i < m;i++)
        {
            long long change = s2*(m-i);
            long long tempResult = originResult + change;
            //printf("The temp result is %lld\n",tempResult);
            if(llabs(tempResult) < llabs(finalResult))
            {
                finalResult = tempResult;
                fieldResult = i;
                //printf("Find field %d is better\n",i);
            } 
        }
        printf("%ld\n",fieldResult+1);
    }
    
    free(arr);
    return 0;

}