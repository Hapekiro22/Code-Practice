//�����ֻ�����

#include<stdio.h>

int main()
{
	char c;
	int count = 0, max_count = 11;
	int pass ;
	
	while((c = getchar()) != EOF)
	{

		 if(!(c>='0'&&c<='9'))
		 {
		 	pass = 0;
		 }
		 if((count = 0)&&(c != '1'))
		 {
            pass = 1;
		 }
		 if((count = 1)&&((c = '1')||(c='2')||(c='9')))
		 {
            pass = 2;
		 }
		 
		 count++;	
	}
	
    if(count != max_count)
    {
    	printf("%d",count);
		return 0;
	}
	if(pass = 0)
	{
		printf("�ַ����д��ڷ������ַ�");
		return 0;
	}
	if(pass = 1)
	{
		printf("��1λ���Ϸ�");
		return 0;
	}
	if(pass = 2)
	{
		printf("��2λ���Ϸ�");
		return 0;	 	
	}
	
	return 0;
	
}

