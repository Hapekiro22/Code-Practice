#include<stdio.h>

int main()
{
    int a,b;
	int x = 127  , n = 10;
	x = ((x%(1<<(n-1)))<<(32 - n))|((x&((1<<(32-n))-1))>>(n));
	printf("%d\n",a=((x%(1<<(n-1)))<<(32 - n)));
	printf("%d\n",b=(x&((1<<(32-n))-1))>>(n));
	printf("%d\n",x);
	
	
	x = 1;
	n = 8;
	x = ((x%(1<<(n-1)))<<(32 - n))|((x&((1<<(32-n))-1))>>(n));
	printf("%d\n",a=((x%(1<<(n-1)))<<(32 - n)));
	printf("%d\n",b=(x&((1<<(32-n))-1))>>(n));
	printf("%d\n",x);
	
	return 0;
}
