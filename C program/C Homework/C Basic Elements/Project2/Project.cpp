#include <stdio.h>

int main() {
	/**********Begin**********/
    int month[12] =  {Jan = 31, Feb = 28, Mar = 31, Apr = 30, May = 31, Jun = 30, Jul = 31, Aug = 31, Sep = 30, Oct = 31, Nov = 30, Dec = 31};
    char *Month[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int year, leap, i;

    scanf("%d",&year);
    if((year%400==0)||(year%4==0&&year%100!=0))
    {
        leap = 0;
    }
    else
    {
        leap = 1;
    }

    for (i = 0; i < 12; i++)
    {
        printf("%s: %d\n",Month[i],month[i]);
    }

	/**********End**********/
	return 0;
}
