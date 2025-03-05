//取二进制数部分字节 
#include<stdio.h>


int main()
{
	short x;
	short m,n;
	scanf("%hx %hu %hu",&x,&m,&n);
	
	if(!((m>=0)&&(m<=15)))	
	{
		printf("wrong number!");
		return 0;
	}

	x = x&(((1<<(m+n))-1)-((1<<m)-1));

    x = x<<(17-m-n-1);
    printf("%hx",x);
    
    return 0;
    
}
