//本题仅作为验证程序 无实际意义
#include <stdio.h>
#include <stdlib.h>

char u[] = "UVWXYZ", v[] = "XYZ";
struct T
{
    int x;
    char c;
    char *t;
} a[] = {{11,'A',u},{100,'B',v}},*p=a;

int main()
{
    int outnum;   
        scanf("%d", &outnum);
        switch(outnum)
        {
            case 1:
                p=a;
                printf("%d\n",(++p)->x);
                break;
            case 2:
                char c1;
                c1 = (p++,p->c);
                printf("%c\n",c1);
                break;
            case 3:
                //p=a;
                char c;
                c = (*p++->t,*p->t);
                printf("%c\n",c);
                break;
            case 4:
                p=a;
                printf("%c\n",*(++p)->t);
                break;
            case 5:
                p=a;
                printf("%c\n",*++p->t);
                break;
            case 6:
                p=a;
                printf("%c\n",++*p->t);
                break;
            case 0:
                exit(0);
    }

}