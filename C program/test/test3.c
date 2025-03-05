#include<stdio.h>
enum { S0, S1, S2} ; 
int main( void )              
{	
    int i, state=S0;
    char s[] = "a(b[c(de)f]g)h";
    char x[64], xi=0, y[64], yi=0;
    for(i=0; s[i]; i++){
        switch(state) {
			case S0:
			 	if(s[i] == '[') state = S1; break;
			case S1:
                if(s[i] == ']') state = S0;
                else if(s[i] == '(') state = S2;
                else if(s[i] == ')');
                else x[xi++] = s[i];
				//break;
            case S2:
                if(s[i] == ')') state = S1;
                else if(s[i] == '(' || s[i] == ']');
                else y[yi++] = s[i];
				//break;
	    }
    }
    x[xi] = '\0';
    y[yi] = '\0';
    printf("%s  %s\n", x, y);
	return 0;
}

