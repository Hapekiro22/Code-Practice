#include<stdio.h>

long long sum_fac(int n);

int main(void)
{
	int k;
	for(k=1; k<=20; k++)
		printf("k=%d the sum is %lld\n",k,sum_fac(k));
	return 0;
}

long long sum_fac(int n)
{
    long long sum,fac=1;
    int i;
    for(i = 1;i<=n;i++)
    {fac = fac*i;}\
    if(n>0)
    {
        sum = sum_fac(n-1) + fac;
        printf("%d  ",fac);
        return sum;
    }
    else 
    {
        return 0;
    }
    
}