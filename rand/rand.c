#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BASE 2

int main()
{
    srand(time(NULL));
    printf("%d", rand() % BASE);
    return 0;
}
//1 = 爪刀
//2 = 能量剑
//0 = 匕首

