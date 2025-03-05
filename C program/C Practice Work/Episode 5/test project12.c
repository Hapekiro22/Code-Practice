#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

int pathCount = 0;

void PrintPath(int **maze, Point *path, int step, int row, int col) {
    printf("路径 %d:\n", ++pathCount);
    int **solution = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        solution[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            solution[i][j] = 0;
        }
    }

    for (int i = 0; i < step; i++) {
        solution[path[i].x][path[i].y] = 1;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                printf("%d", solution[i][j]);
            } else {
                printf("%d ", solution[i][j]);                                              
            }
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < row; i++) {
        free(solution[i]);
    }
    free(solution);
}

int isSafe(int **maze, int x, int y, int row, int col, int **visited) {
    return (x >= 0 && x < row && y >= 0 && y < col && maze[x][y] == 1 && !visited[x][y]);
}    // 1表示可以通过，0表示不可以通过

void dfs(int **maze, int x, int y, int row, int col, int **visited, Point *path, int step) {
    if (x == row - 1 && y == col - 1) {
        path[step].x = x;
        path[step].y = y;
        PrintPath(maze, path, step + 1, row, col);
        return;
    }

    visited[x][y] = 1;   // 1表示已经访问过
    path[step].x = x;
    path[step].y = y;

    int rowMove[] = {0, 1, 0, -1};
    int colMove[] = {1, 0, -1, 0};

    for (int k = 0; k < 4; k++) {
        int newX = x + rowMove[k];
        int newY = y + colMove[k];
        if (isSafe(maze, newX, newY, row, col, visited)) {
            dfs(maze, newX, newY, row, col, visited, path, step + 1); 
        }
    }

    visited[x][y] = 0;
}

void MazeSolve(int **maze, int row, int col) {
    int **visited = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        visited[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            visited[i][j] = 0;
        }
    }

    Point *path = (Point *)malloc((row * col) * sizeof(Point));  
    dfs(maze, 0, 0, row, col, visited, path, 0); 

    for (int i = 0; i < row; i++) {
        free(visited[i]);
    }
    free(visited);
    free(path);
}

int main() {
    int row, col;
    scanf("%d %d", &row, &col);

    int **maze = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        maze[i] = (int *)malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    MazeSolve(maze, row, col);

    for (int i = 0; i < row; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;                           
}