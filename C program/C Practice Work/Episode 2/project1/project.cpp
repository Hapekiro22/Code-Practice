#include<stdio.h>
#define PI 3.14159
int main(){
	int f;
	short p, k;
	double c, r, s;
	
	/*任务1*/
	printf("Input Fahrenheit:");
	scanf("%d",&f);
	c=(5*(f-32))/9;
	printf("\n %d(F)=%.2f(C)\n\n",f,c);
	/*任务2*/
	printf("input the radius r:");
	scanf("%lf",&r);
	s = PI * r * r;
	printf("\nThe acreage is %.2lf\n\n", s);
	/*任务3*/
	k=0xa1b2, p=0x8423;
	int newint; 
	newint = (p&0xff00)|((k>>8)&((1<<8) - 1));
	printf("new int = %#x\n\n",newint);
	return 0;  
}
