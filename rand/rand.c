#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASE 3

int main()
{
    srand(time(NULL));
    printf("%d", rand() % BASE);
    return 0;
}
//1 = Guitar
//2 = Game
//0 = again

