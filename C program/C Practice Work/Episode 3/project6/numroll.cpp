//full arrange
#include<stdio.h>

int check(int *count)
{
	int i = 0;
	while(i < 10)
	{
		if(count[i] > 1) return 0;
		else i++;
	}
	
	return 1;
}

int main()
{
	int x,checkn,rest;
	scanf("%d",&x);
	
	int i,j,a,b;
	for(i = 1000;i<100000;i++)
	{
		int count[10] = {0};
		j = i * x;
		if(j>100000) break;
		a = i,b = j;
		int s = 0;
		
		while(s<5)
		{
		    rest = a%10;
			count[rest]+=1;
			a = a / 10;
			s++; 
		}
		s = 0;
		while(s<5)
		{
		    rest = b%10;
			count[rest]+=1;
			b = b / 10;
			s++; 
		}
		
		checkn = check(count);
		if(checkn)
		 {printf("%05d/%05d=%d\n",j,i,x);}
	}
	
	
	return 0;
	
}
