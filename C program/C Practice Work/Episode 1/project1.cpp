#include<stdio.h>
#include<math.h>

int main()
{
	long x, y;
	long i = 0;
	
	for(i = 1; i < 10000 ;i++)
	{
		x = sqrt(i + 100);
		y = sqrt(i + 268);
		if((!(x*x - (i + 100)) && (!(y*y - (i + 268)))))
		{
			printf("%d\n",i);
		}
	}
	
	return 0;
	
}
