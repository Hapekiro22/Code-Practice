//Mersene Num

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
	long int m;
	scanf("%ld",&m);
	int i,msnum = 1;
	
	for(i = 1;msnum <= m;i++)
	{
	    msnum = ( 1<<i ) - 1;
		if(msnum>=m) break;
		if(!prime(i)) continue;
		if(prime(msnum)){printf("M(%d) %d\n",i,msnum);}
	}
	
	return 0;
} 
