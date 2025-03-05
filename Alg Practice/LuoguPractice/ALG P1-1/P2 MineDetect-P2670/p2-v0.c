#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char **map = (char**)malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++)
    {
        map[i] = (char*)malloc(m * sizeof(char));
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            map[i][j] = 0;
        }
    }
    int count = 0;
    char c;
    while(count < m*n)
    {
        c = getchar();
        if(c == '\n')
        {
            continue;
        }
        if(c == '*')
        {
            int x = count / m;
            int y = count % m;
            map[x][y] = '*';
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    if(x + i >= 0 && x + i < n && y + j >= 0 && y + j < m && map[x + i][y + j] != '*')
                    {
                        map[x + i][y + j]++;
                    }
                }
            }
        }
        count++;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == '*')
            {
                printf("*");
            }
            else
            {
                printf("%d",map[i][j]);
            }
        }
        printf("\n");
    }

    free(map);
    return 0;

}