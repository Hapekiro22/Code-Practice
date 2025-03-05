#include<stdio.h>

int main()
{
	int count = 1, sum = 0, num, pos_num = 0, pos_count = 0;
	float avg;
	while( count <= 10 )
	{
		scanf("%d",&num);
		if(num > 0)
		{
			pos_num = num;
			sum = sum + pos_num;
			pos_count ++;
		}
		count++;
	}
	
	if( pos_count == 0 )
	{
		pos_count = 1;
	}
	
	printf("%d\n",pos_count);
	avg = (float)sum / pos_count;
	printf("%d\n",sum);
	printf("%.1f\n",avg);
	
	return 0;
	
	
	
}
