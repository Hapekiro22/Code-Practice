//IPµØÖ·±àÒë 

#include<stdio.h>

int main()
{
	unsigned long mask = (1<<8)-1,step = 0;
	unsigned long num;
	unsigned int trans_num[4];
	
	while((scanf("%lu",&num))!=EOF)
	{
		while(step<=3)
		{
			trans_num[step] = (num&(mask<<(8*step))) >> (8*step);	
			step++;
		}
		printf("%u.%u.%u.%u\n",trans_num[3],trans_num[2],trans_num[1],trans_num[0]);
		step = 0;
	}
	
	return 0;
} 
