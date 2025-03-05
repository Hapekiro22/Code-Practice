//检验手机号码

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
		printf("字符串中存在非数字字符");
		return 0;
	}
	if(pass = 1)
	{
		printf("第1位不合法");
		return 0;
	}
	if(pass = 2)
	{
		printf("第2位不合法");
		return 0;	 	
	}
	
	return 0;
	
}

