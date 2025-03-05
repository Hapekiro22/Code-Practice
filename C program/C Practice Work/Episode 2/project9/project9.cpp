//��ĸ���� 
#include<stdio.h>

int main()
{
	char c,a,b;
	int count,part;
	unsigned int move; 
	
	
	while((c = getchar())!=EOF)
	{
	    move = (c>>6) % 6;
		int i = 0;
		while(i<=4)
		{
			a = (c&(1<<i))<<1;
			b = (c&(1<<(i+1)))>>1;
			c = c&(((1<<8) - 1)-(((1<<2)-1)<<i));                                             //Ĩ����iλ���i+1λ 
			c = (c|a)|b;  
		    i+=2;                                                                             //��ɵ�iλ���� 
		}
		part = c&((1<<6)-1);                                                                  //ȡ��ǰ��λ
		part = ((part&((1<<(6-move))-1))<<move)|((part&(((1<<move)-1)<<(6-move)))>>(6-move));//part��ѭ��moveλ 
		c = (c&(((1<<2)-1)<<6))|part;                                                        //c�ĸ�λ��part���
		printf("%c",c);
		 
		
	}
	
	return 0;
}
