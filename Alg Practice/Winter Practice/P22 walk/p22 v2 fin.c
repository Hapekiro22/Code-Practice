#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WAYS 12
#define NONE 10000

typedef struct cell {
    int color;
    int x;
    int y;
    int direction[]
} cell;

int DFS(cell **Matrix,cell *start, int m);

int main()
{
    FILE *fp = fopen("walk/walk1.in", "r");
    int m,mincost;
    fscanf(fp, "%d", &m);
    cell **Matrix = (cell **)malloc(m * sizeof(cell *));
    int n;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < m; i++)
    {
        Matrix[i] = (cell *)malloc(m * sizeof(cell));
        for (int j = 0; j < m; j++)
        {
            Matrix[i][j].color = -1;
            Matrix[i][j].x = i;
            Matrix[i][j].y = j;
            for (int k = 0; k < WAYS; k++)
            {
                Matrix[i][j].direction[k] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x, y, c;
        fscanf(fp, "%d %d %d", &x, &y, &c);
        Matrix[x - 1][y - 1].color = c;
    }
    //fclose(fp);
    mincost = DFS(Matrix,*Matrix,m);
    if(mincost >= NONE)
        printf("-1\n");
    else
        printf("%d\n", mincost);
    fclose(fp);
    return 0;
}

//十二个方向，0-3为上下左右共移动一次，4-11为横纵方向共移动两次
int DFS(cell **Matrix, cell *start,int m)
{
    int mincost = 0x7fffffff,cost = 0;
    printf("(%d,%d)\n",start -> x,start -> y);
    cell *end = &Matrix[m - 1][m - 1];
    if(end -> color == -1)
        return NONE;
    if(start -> color == -1)
        return NONE;
    for(int i = 0;i < WAYS;i++)
    {
        if(start -> direction[i] == 1)
        {
            cell *next = NULL;
            switch(i)
            {
                case 0:
                    if(start -> x - 1 >= 0 && (&Matrix[start -> x - 1][start -> y]) -> color != -1)
                       {
                            next = &Matrix[start -> x - 1][start -> y];
                            next -> direction[1] = 0;
                            if(next -> color != start -> color)
                                cost += 1;
                       }
                       break;
                case 1:
                    if(start -> x + 1 < m && (&Matrix[start -> x + 1][start -> y]) -> color != -1)
                       {
                            next = &Matrix[start -> x + 1][start -> y];
                            next -> direction[0] = 0;
                            if(next -> color != start -> color)
                                cost += 1;
                       }
                       break;
                case 2:
                    if(start -> y - 1 >= 0 && (&Matrix[start -> x][start -> y - 1]) -> color != -1)
                       {
                            next = &Matrix[start -> x][start -> y - 1];
                            next -> direction[3] = 0;
                            if(next -> color != start -> color)
                                cost += 1;
                       }
                        break;
                case 3:
                    if(start -> y + 1 < m && (&Matrix[start -> x][start -> y + 1]) -> color != -1)
                       {
                            next = &Matrix[start -> x][start -> y + 1];
                            next -> direction[2] = 0;
                            if(next -> color != start -> color)
                                cost += 1;
                       }
                        break;
                case 4:
                    if(start -> x - 2 >= 0 && (&Matrix[start -> x - 2][start -> y]) -> color != -1)
                       {
                            next = &Matrix[start -> x - 2][start -> y];
                            next -> direction[5] = 0;
                            if(next -> color != start -> color)
                                cost += 3;
                            else cost += 2;
                       }
                        break;
                case 5:
                    if(start -> x + 2 < m && (&Matrix[start -> x + 2][start -> y]) -> color != -1)
                       {
                            next = &Matrix[start -> x + 2][start -> y];
                            next -> direction[4] = 0;
                            if(next -> color != start -> color)
                                cost += 3;
                            else cost += 2;
                       }
                        break;
                case 6:
                    if(start -> y - 2 >= 0 && (&Matrix[start -> x][start -> y - 2]) -> color != -1)
                       {
                            next = &Matrix[start -> x][start -> y - 2];
                            next -> direction[7] = 0;
                            if(next -> color != start -> color)
                                cost += 3;
                            else cost += 2;
                       }
                        break;
                case 7:
                    if(start -> y + 2 < m && (&Matrix[start -> x][start -> y + 2]) -> color != -1)
                       {
                            next = &Matrix[start -> x][start -> y + 2];
                            next -> direction[6] = 0;
                            if(next -> color != start -> color)
                                cost += 3;
                            else cost += 2;
                       }
                        break;
                case 8:
                    if(start -> x - 1 >= 0 && start -> y - 1 >= 0 && (&Matrix[start -> x - 1][start -> y - 1]) -> color != -1)
                       {
                            next = &Matrix[start -> x - 1][start -> y - 1];
                            next -> direction[9] = 0;
                            if(next -> color != start -> color)
                                cost += 3;
                            else cost += 2;
                       }
                        break;
                case 9:
                    if(start -> x + 1 < m && start -> y + 1 < m && (&Matrix[start -> x + 1][start -> y + 1]) -> color != -1)
                       {
                            next = &Matrix[start -> x + 1][start -> y + 1];
                            next -> direction[8] = 0;
                            if(next -> color != start -> color)
                                cost += 3;
                            else cost += 2;
                       }
                        break;
                case 10:
                    if(start -> x - 1 >= 0 && start -> y + 1 < m && (&Matrix[start -> x - 1][start -> y + 1]) -> color != -1)
                       {
                            next = &Matrix[start -> x - 1][start -> y + 1];
                            next -> direction[11] = 0;
                            if(next -> color != start -> color)
                                cost += 3;
                            else cost += 2;
                       }
                        break;
                case 11:
                    if(start -> x + 1 < m && start -> y - 1 >= 0 && (&Matrix[start -> x + 1][start -> y - 1]) -> color != -1)
                       {
                            next = &Matrix[start -> x + 1][start -> y - 1];
                            next -> direction[10] = 0;
                            if(next -> color != start -> color)
                                cost += 3;
                            else cost += 2;
                       }
                        break;
            }
            if(next != NULL)
            {
                if(next == end)
                {
                    if(cost < mincost)
                        mincost = cost;
                }
                else
                {
                    cost += DFS(Matrix,next,m);
                }
            }
        }
    }
    int flag = 0;
    for(int i = 0;i < WAYS;i++)
    {
        if(start -> direction[i] == 1)
            flag = 1;
        start -> direction[i] = 1;  //恢复方向
    }
    if(flag == 0 && start != end)
        return NONE;
    return mincost;
}