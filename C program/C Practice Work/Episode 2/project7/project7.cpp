//×Ö·û×ª»»

#include<stdio.h>

int main()
{
	char str[81];
	int k,i = 0;
	scanf("%[^\n]",str);
	scanf("%d",&k);
	
	while(i<=80)
	{
		if((str[i]>='A')&&(str[i]<='Z'))
		{
			str[i] = ((str[i] + k - 66) % 26) + 65;
		}
		i++;
	}
	
	i = 0;
	
    char change;
	while(i<=80)
	{
		
		if((str[i] != '\0')&&(str[i+1] == '\0'))
		{
			break;
		}
		else if(str[i] == '\0')
		{
			printf("%c",str[i]);
			break;
		}
		else
		{
			change = str[i+1];
			str[i+1] = str[i];
			str[i] = change;
			printf("%c%c",str[i],str[i+1]);
		}
		
		i += 2;
	}
	
	return 0;
	
} 
