#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEFT -1
#define RIGHT 1
#define MAX_NAME_LEN 20

typedef struct toy
{
    int direction;
    char *name;
} toy;

int main()
{
    long n,m;
    scanf("%ld %ld",&n,&m);
    toy *toys = (toy *)malloc(sizeof(toy) * n);
    for (int i = 0; i < n; i++)
    {
        toys[i].name = (char *)malloc(sizeof(char) * MAX_NAME_LEN);
        scanf("%d %s", &toys[i].direction, toys[i].name);
        if(toys[i].direction == 0)
        {
            toys[i].direction = RIGHT;
        }
        else
        {
            toys[i].direction = LEFT;
        }
    }

    //规定，面对内圈，左转为-1，右转为1
    int position = 0;
    for(int i = 0;i < m;i++)
    {
        //printf("Now at %s\n",toys[position].name);
        long step;
        int direction;
        scanf("%d %ld",&direction,&step);
        if(direction == 0)
        {
            direction = LEFT;
        }
        else
        {
            direction = RIGHT;
        }
        position += toys[position].direction * direction * step;
        position = (position + n) % n;
    }
    printf("%s",toys[position].name);

    for(int i = 0;i < n;i++)
    {
        free(toys[i].name);
    }
    free(toys);
    return 0;

}