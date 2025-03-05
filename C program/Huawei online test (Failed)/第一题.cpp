#include<stdio.h>
#include<string.h>

int main()
{
	int count = 0;
	char number[20];
	//char check1[4] = {'2','0','2','4'}, check2[4] = {'2','0','2','3'};
	
	scanf("%s",number);
	
	count = strlen(number);
	
	if(count != 10)
	{
		printf("No");
		return 0;
	}
		
           //本科生检测 
	
    if((number[4] == '3' || number[4] == '4') && (number[0] == 'U'))
    {
    	printf("Yes");
	}
	else
	{
		printf("No");
	}
	
	
	
 /*   while( (number[count] != '\0') && pass )
	{
		if(count <= 4)
		{
			if((number[count] == check1[count - 1])||(number[count] == check2[count - 1]))
			{
				pass = 1;
			}
			else
			{ 
			    break;
			}
		}
		count++;	     //年份检测 
		
	} 	
	
	printf("%d,%d\n",pass,count);
	
	if(count == 10)
	{
		pass = 1;
	}
	else
	{
		pass = 0;        //位数检测 
	}      */
	

	
	/*if(pass)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}*/
	
	return 0;
	
}
