#include<stdio.h>

int main()
{
	short k,p;
	scanf("%hd",&k);
	
	k = (k >> 8)&0xff;  //移动二进制码补位不一定是0 
	
	printf("%hd\n",k);
}
