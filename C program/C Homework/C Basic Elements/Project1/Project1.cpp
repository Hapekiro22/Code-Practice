#include<stdio.h>

int main()
{
	short k,p;
	scanf("%hd",&k);
	
	k = (k >> 8)&0xff;  //�ƶ��������벹λ��һ����0 
	
	printf("%hd\n",k);
}
