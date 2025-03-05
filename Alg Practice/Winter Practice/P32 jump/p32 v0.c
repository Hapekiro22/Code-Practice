#include <stdio.h>
#include <stdlib.h>

typedef struct dot {
    long long x;
    long long y;
} dot;

int main()
{
    FILE *fp = fopen("jump/jump2.in", "r");
    int n,m;
    fscanf(fp, "%d %d", &n, &m);
    dot *move = (dot *)malloc(sizeof(dot) * n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%lld %lld", &move[i].x, &move[i].y);
    }
    dot *dots = (dot *)malloc(sizeof(dot) * m);
    for (int i = 0; i < m; i++) {
        fscanf(fp, "%lld %lld", &dots[i].x, &dots[i].y);
    }
    fclose(fp);

    for(int i = 0;i < m;i++)
    {
        long long x = dots[i].x;
        long long y = dots[i].y;
        for(int j = 0;j < n;j++)
        {
            x += move[j].x;
            y += move[j].y;
        }
        dots[i].x = x;
        dots[i].y = y;
    }
    for(int i = 0;i < m;i++)
    {
        printf("%lld %lld\n",dots[i].x,dots[i].y);
    }
    free(move);
    free(dots);
    return 0;
}