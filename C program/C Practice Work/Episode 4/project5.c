//e的级数计算
#include<stdio.h>

double mulx(double x,int n);
//long fac(int n);

double sum(double x,int n)
{
    int i;
    long fac = 1;
    double sum = 0;
    for(i = 1;i<=n;i++)
    {
        fac = fac*i;
        sum = sum + mulx(x,i)/fac;
        printf("%ld\n",fac);
    }
    return sum;
}

double mulx(double x,int n)
{
	int i;
	double z=1.0;
	for(i=0;i<n;i++)
	{
		z=z*x;
	}
	return z;
}

int main()
{
	double x;
	int n;
	scanf("%lf%d",&x,&n);
	printf("The result is %lf",sum(x,n));
	return 0;
} 