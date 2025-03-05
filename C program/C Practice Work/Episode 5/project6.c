#include<stdio.h>
int transistion(int num,char numc[]) 
{
	unsigned int mask = 1;
	int i,length;
	
	length = 8 * sizeof(num);
	mask = mask << length - 1;
	
	for(i = 0; i < length; i++)
	{
        //if((!(i%4))&&(i!=0)) printf(" ");
		if(((mask >> i)&num)==0)
			numc[i] = '0';
		else
			numc[i] = '1';
	}
    numc[1000-length] = '\0';
	return 1;
}

int main()
{
	int num;
    char numc[1000];
	scanf("%d",&num);
	transistion(num,numc);
    for(int i = 0; i < 1000; i++)
    {
        if(numc[i] == '\0') break;
        if(i%4==0&&i!=0) printf(" ");
        printf("%c",numc[i]);
    }
	return 0;
}
