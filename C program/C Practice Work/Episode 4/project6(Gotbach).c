//哥德巴赫猜想

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
	
	if(n == 1) return 0;
    if(n == 2) return 1;
	
	else  return 1;
	
}

int main()
{
    int n;
    scanf("%d",&n);

    int i;
    for(i=1; i<=(n/2); i+=2)
    {
        if(prime(i))
        {
            if(prime(n-i))
            {
                printf("%d=%d+%d",n,i,n-i);
                break;
            }
            else continue;
        }
    }

    return 0;
}