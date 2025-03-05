//将一个二维矩阵逆时针旋转90度
#include <stdio.h>
#include <stdlib.h>

int **rotateMatrix(int **matrix, int row, int col);
void printMatrix(int **matrix, int row, int col);

int main()
{
    int row,col;
    scanf("%d %d",&row,&col);
    int **matrix = (int **)malloc(row*sizeof(int *));
    for(int i=0;i<row;i++)
    {
        matrix[i] = (int *)malloc(col*sizeof(int));
        for(int j=0;j<col;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }

    int **rotated = rotateMatrix(matrix,row,col);
    printMatrix(rotated,col,row);

    for(int i=0;i<row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

int **rotateMatrix(int **matrix,int row,int col)
{
    int **rotatedMatrix = (int **)malloc(col*sizeof(int *));
    for(int i=0;i<col;i++)
    {
        rotatedMatrix[i] = (int *)malloc(row*sizeof(int));
        for(int j=0;j<row;j++)
        {
            rotatedMatrix[i][j] = matrix[j][col-i-1];
        }
    }

    int temp,i,j;
    for(i=0;i<row;i++)                  //先转置
    {
        for(j=0;j<col;j++)
        {
            *(*(rotatedMatrix+j)+i) = *(*(matrix+i)+j);
        }
    }
    for(i=0;i<col/2;i++)                  //再将列逆序排列
    {
        for(j=0;j<row;j++)
        {
            temp = *(*(rotatedMatrix+i)+j);
            *(*(rotatedMatrix+i)+j) = *(*(rotatedMatrix+col-1-i)+j);
            *(*(rotatedMatrix+col-1-i)+j) = temp;
        }
    }                           

    return rotatedMatrix;
    
}

void printMatrix(int **matrix,int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(j==col-1)
                printf("%d",matrix[i][j]);
            else
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return;
}