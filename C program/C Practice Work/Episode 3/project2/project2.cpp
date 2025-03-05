//ºÏÊı¼ì²é

#include<stdio.h>
#include<math.h>

int prime(int n)
{
	int up = sqrt(n);
	int k;
	for(k = 2;k <= up;k ++)
	{
		if(!(n%k)) return 0;
	}
	
	if(n == 1) return 1;
	
	else  return 1;
	
}


int main()
{
	int rangeup,rangedown = 1, n;
	scanf("%d",&n);
	int i = 0;
	while(i<n-1) {rangedown = rangedown * 10; i++;}
	rangeup = rangedown * 10;
	
	int check,pass = 0,save;
	for(check = rangedown; check < rangeup; check++)
	{
		save = check;
		while(check)
		{
			pass = prime(check);
			if(pass == 1) break;
			check = check / 10;
		}
		check = save;
		if(!pass) printf("%d ",check);
	}

	

	return 0;
} 
