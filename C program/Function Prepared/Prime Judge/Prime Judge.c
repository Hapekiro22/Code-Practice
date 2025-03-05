int prime(int n)
{
	int up = sqrt(n);
	int k;
	for(k = 2;k <= up;k ++)
	{
		if(!(n%k)) return 0;
	}
	
	if(n == 1) return 0;
	else if(n == 2) return 1;
	else  return 1;
	
}
