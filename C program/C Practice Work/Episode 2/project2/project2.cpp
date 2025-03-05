//计算一个十进制n的各个数位之和

#include<stdio.h>

int main()
{
	int count = 0, sum = 0;
	int num,save;
	scanf("%d",&num);
	
	save = num;
	
	do
	{
		sum = sum + num%10;
		num = num/10;
		count++;
	}
	while(num);
	
	printf("%d是%d位数，且各位数字之和为%d。",save,count,sum);
	
	return 0;
	
} 
