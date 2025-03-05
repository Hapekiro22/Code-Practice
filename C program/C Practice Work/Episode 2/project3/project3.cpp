//Õ≥º∆’€µ„

#include<stdio.h>

int main()
{
	int days, count = 0;
	scanf("%d",&days);
	int sold[days], i = 0;
	for(i = 0;i < days;i++)
	{
		scanf("%d",&sold[i]);
	}
	
	int j;
	for(j = 0;j < days - 2;j++)
	{
		if(((sold[j+1]-sold[j])*(sold[j+2]-sold[j+1]))<=0)
		{
			count ++ ;
		}
	}
	
	printf("%d",count);
	
	return 0;
	
} 
