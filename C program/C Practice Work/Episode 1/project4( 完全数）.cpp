#include<stdio.h>

int sigma(int n)
{
	int d = 0, sum = 0;
	for(d = 1; d < n; d++)
	{
		if(!(n%d))
		{
			sum = sum + d;
		}
	}
	
	return sum;
}

int main()
{
	int num , i;
	for(i = 1;i <= 1000; i++)
	{
		if(!(i - sigma(i)))
		{
			printf("%8d ",i);
		}
	}
	
	return 0;
}
