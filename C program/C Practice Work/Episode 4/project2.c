#include<stdio.h>
#include<assert.h>

#define R

int integer(float s);

int main()
{
     float r,s;
     int s_integ;
     scanf("%f",&r);

    #ifdef R
        s = 3.14159 * r * r;

        s_integ = integer(s);
        assert((s-s_integ)<0.5);
        printf("The integer fraction of area is %d",s_integ);
    #endif

    return 0;

}

int integer(float s)
{
    int s_integ;
    if((s - s_integ)>0.5)
    {
        s_integ = (int)s + 1;
    }
    else{
        s_integ = (int)s;
    }

    return s_integ;

}