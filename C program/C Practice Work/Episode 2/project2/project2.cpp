//����һ��ʮ����n�ĸ�����λ֮��

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
	
	printf("%d��%dλ�����Ҹ�λ����֮��Ϊ%d��",save,count,sum);
	
	return 0;
	
} 
