#include<stdio.h>

int main()
{
	char a,c;
	a = 1;
	c = 66;
	int i = 0;
	a = 1<<8 -1;
	printf("%d\n",(((1<<8) - 1)-(((1<<2)-1)<<i)));
	printf("%d\n",(((1<<2)-1)));
	printf("%d",((1<<7)-1));
	
	return 0;
}
