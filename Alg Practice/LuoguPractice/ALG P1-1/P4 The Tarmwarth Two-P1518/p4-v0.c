#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 10
#define NUM 2
#define WAYS 4

typedef struct node
{
    int x, y;
    int barrier;
} node;

typedef struct object
{
    int x,y;
    int direction;
} object;

void move(object *ob,node **map)
{
    int loc_x = ob->x;
    int loc_y = ob->y;
    int dir = ob->direction;
    int new_x = loc_x, new_y = loc_y;
    switch (dir)
    {
        case 0:
            new_x = loc_x - 1;
            break;
        case 1:
            new_y = loc_y + 1;
            break;
        case 2:
            new_x = loc_x + 1;
            break;
        case 3:
            new_y = loc_y - 1;
            break;
        default:
            break;
    }
    if(new_x < 0 || new_x >= LEN || new_y < 0 || new_y >= LEN)
    {
        ob->direction = (dir + 1) % WAYS;
        return;
    }
    if(map[new_x][new_y].barrier)
    {
        ob->direction = (dir + 1) % WAYS;
        return;
    }
    ob->x = new_x;
    ob->y = new_y;

    return;
}

int main()
{
    node **map = (node **)malloc(LEN * sizeof(node *));
    for (int i = 0; i < LEN; i++)
    {
        map[i] = (node *)malloc(LEN * sizeof(node));
    }
    object farmer,cow;
    for(int i = 0; i < LEN; i++)
    {
        for(int j = 0; j < LEN; j++)
        {
            char c = getchar();
            map[i][j].x = i;
            map[i][j].y = j;
            if(c == '*')
                map[i][j].barrier = 1;
            else
                map[i][j].barrier = 0;
            if(c == 'F')
            {
                farmer.x = i;
                farmer.y = j;
                farmer.direction = 0;
            }
            if(c == 'C')
            {
                cow.x = i;
                cow.y = j;
                cow.direction = 0;
            }
        }
        getchar();
    }

    int steps = 0,flag = 0;
    int originfarmer_x = farmer.x,originfarmer_y = farmer.y;
    int origincow_x = cow.x,origincow_y = cow.y;
    while(1)
    {
        move(&farmer,map);
        move(&cow,map);

        //printf("farmer: %d %d %d\n",farmer.x,farmer.y,farmer.direction);
        //printf("cow: %d %d %d\n",cow.x,cow.y,cow.direction);

        steps++;
        if(farmer.x == cow.x && farmer.y == cow.y)
        {
            flag = 1;
            break;
        }

        if(steps > 1 && farmer.x == originfarmer_x && farmer.y == originfarmer_y && cow.x == origincow_x && cow.y == origincow_y && farmer.direction == 0 && cow.direction == 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag)
        printf("%d",steps);
    else
        printf("0");

    free(map);
    return 0;
}