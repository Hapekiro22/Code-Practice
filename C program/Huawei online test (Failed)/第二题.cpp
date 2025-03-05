#include<stdio.h>
#include<stdlib.h>

int main()
{
	long long int k,x1,x2,y1,y2;
	int gapx = 0, gapy = 0, gap = 0;
	int check = 0;
	
	scanf("%d",&k);
	scanf("%d %d",&x1,&y1);
	scanf("%d %d",&x2,&y2);
	
	gapx = abs(x2 - x1);
	gapy = abs(y2 - y1);
	gap = gapx + gapy;
	
	if((gap <= k) && (!((gap - k)%2)))
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	
	return 0;
	
	
}
