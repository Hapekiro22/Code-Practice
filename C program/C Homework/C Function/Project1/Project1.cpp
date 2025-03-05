//双掷骰子 第一轮7或11win 2 3 12 lose 之后7lose

#include<stdio.h>
#include<stdlib.h>
#define MAXNUM 6

void  diceGame(int randSeed)
{
	int sum,t;
	int count = 1;
	int target;
	
	srand(randSeed);
	
	if(count==1)
	{
		sum = rand();
		t = rand();
		sum = sum + t;
		sum = sum%MAXNUM+1;
		if((sum==7)||(sum==11))
		{
			printf("Round 1:  Score:%d  Win!\n",sum);
			return;
		}
		else if((sum==2)||(sum==3)||(sum==12))
		{
			printf("Round 1:  Score:%d  Failed!\n",sum);
			return;
		}
		else
		{
			printf("Round %d:  Score:%d  Continue\n",count,sum);
			count++;
			printf("Next rounds: Score %d:Success, Score 7:Failed, others:Continue\n",sum);
			target = sum;
		}
	}
		while(count>1)
		{
			sum = rand();
			t = rand();
			sum = sum + t;
			if(!(sum%6)) sum = 6;
			else sum %= 6;
			if(sum==target)
			{
				printf("Round %d:  Score:%d  Win!\n",count,sum);
				return;
			}
			else if(sum!=7)
			{
				printf("Round %d:  Score:%d  Continue!\n",count,sum);
				count++;
			}
			else
			{
				printf("Round %d:  Score:%d  Failed!\n",count,sum);
				return;
			}
	    }
	
	
}

int main()
{
	int num;
	scanf("%d",&num);
	diceGame(num);
	return 0;
	
}


 
