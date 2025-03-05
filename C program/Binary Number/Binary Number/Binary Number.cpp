#include<stdio.h>
int transistion(int num = 0) 
{
	unsigned int mask = 1;
	int i,length;
	
	length = 8 * sizeof(num);
	mask = mask << length - 1;
	
	for(i = 0; i < length; i++)
	{
		if(((mask >> i)&num)==0)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
	}
	
	//右移动最高位补1； 
	printf("\n");
	
	return 1;
}

int main()
{
	int num;

	scanf("%d",&num);
	transistion(num);
	num = num << 3;
	transistion(num);
	printf("%d\n",num);
	
	return 0;
}
