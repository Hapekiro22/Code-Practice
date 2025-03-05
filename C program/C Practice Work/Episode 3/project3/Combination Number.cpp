//组合数计算 

#include<stdio.h>

int factorial(int n)
{
	int i ,fac = 1;
	for(i = 1;i <= n;i++)
	{
		fac = fac * i;
	}
	return fac;
}

int CombNum (int m,int n)
{
	int comn = 1;
	if(n == 0) return 1;
	comn = factorial(n)/((factorial(n - m))*factorial(m));
	return comn;
}

int range(int n)
{
	int rangenum = 1;
	int i = 0;
	while(i<n-1) {rangenum = rangenum * 10; i++;}
	return rangenum;
}

int main()
{   
    int row;
	scanf("%d",&row);
	int spnum = 3,gap = 2*row-1,gap_count = 1;
	int combnum;
	int i = 0, j = 0, k = 0;
	
	
	while(i<=row)
	{
		while(j <= i)
		{
			while(gap_count<=gap){printf(" "); gap_count++;}
			if(i == 0) printf(" ");
			if(CombNum(j,i)<range(2)) printf("%-4d",CombNum(j,i));
			else if(CombNum(j,i)<range(3)) printf("%-4d",CombNum(j,i));
			else if(CombNum(j,i)<range(4)) printf("%-4d",CombNum(j,i));
			j++;
		}
		i++, gap -= 2;
		j = 0, gap_count = 0;
		printf("\n");
	}
	
	
/*	int n,m;
	n = 8,m = 2;
	printf("%d",CombNum(m,n));*/
	
	return 0;
}
