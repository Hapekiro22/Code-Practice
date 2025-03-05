#include<stdio.h>
#include<string.h>

void transistion(char num = 0) 
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
	
	//右移动最高位补1； 
	printf("\n");
	
}

void CNCharPr(char* ChChar)
{
	int n = strlen(ChChar);
	int i = 0;
	
	while(i < n)
	{
		printf("%s 的第%d个字节十进制码：%d ，二进制码: ",ChChar,i+1,*(ChChar+i));
		transistion((int)*(ChChar+i));
		i++;
	}
	
}

int main()
{
	
	char ChChar[10000];
	scanf("%s",ChChar);
	CNCharPr(ChChar);
	char str[2] = {-80,-84};       //单个字对应字符串 
	printf("%s",ChChar);           //打印字符串 ，也可以用while打印指定字符，部分字符串 
	
	return 0;
	
}

//DevC是采用二字节汉字编码由此可见 
