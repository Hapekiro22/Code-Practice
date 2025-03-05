//Twist PrimeNum

#include<stdio.h>
#include<math.h>

int prime(int n)
{
	int up = sqrt(n);
	int k;
	for(k = 2;k <= up;k ++)
	{
		if(!(n%k)) return 0;
	}
	
	if(n == 1) return 0;
	
	else  return 1;
	
}

int main()
{
	int m;
	scanf("%d",&m);
	int i;
	
	for(i = 1;i < m;i+=2)
	{
		if((prime(i))&&(prime(i+2)))
		{
			printf("(%d,%d) ",i,i+2);
		}
	}
	
	return 0;
}
