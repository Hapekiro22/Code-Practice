#include<stdio.h>
#include<string.h>

int transistion(char num = 0) 
{
	unsigned char mask = 1;
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
	
	//���ƶ����λ��1�� 
	printf("\n");
	
	return 1;
}

void ChCharSc(char* ChChar)
{
	int n = strlen(ChChar);
	int i = 0;
	
	while(i<n)
	{
		printf("%s �ĵ�%d���ֽ�ʮ�����룺%d ����������: ",ChChar,i+1,*(ChChar+i));
		transistion((int)(*(ChChar+i)));
		i++;
	}
	
}

int main()
{
	
	char ChChar[5];
	scanf("%s",ChChar);
	ChCharSc(ChChar);
	char str[2] = {};
	
	return 0;
	
}
