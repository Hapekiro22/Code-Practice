//将一个二维矩阵逆时针旋转90度
//要求从matrix.in读数据，旋转后的矩阵输出到当前目录下的文本文件matrix.out中，该文件有m行，每行有n个整数
//原始矩阵数据存放在当前目录下的文本文件matrix.in中，文件的第一行是两个整数n和m，表示矩阵的行数n和列数m，
#include <stdio.h>
#include <stdlib.h>

int **rotateMatrix(int **matrix, int row, int col);
void printMatrix(int **matrix, int row, int col);

int main()
{
    int row,col;
    FILE *fp;
    if((fp=fopen("matrix.in","r"))==NULL)
    {
        perror("文件打开失败");
        return 0;
    }
    fscanf(fp,"%d %d",&row,&col);
    int **matrix = (int **)malloc(row*sizeof(int *));
    for(int i=0;i<row;i++)
    {
        matrix[i] = (int *)malloc(col*sizeof(int));
        for(int j=0;j<col;j++)
        {
            fscanf(fp,"%d",&matrix[i][j]);
        }
    }
    int **rotated = rotateMatrix(matrix,row,col);
    FILE *fp1;
    if((fp1=fopen("matrix.out","w"))==NULL)
    {
        perror("文件打开失败");
        return 0;
    }
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            if(j==row-1)
                fprintf(fp1,"%d",rotated[i][j]);
            else
            fprintf(fp1,"%d ",rotated[i][j]);
        }
        fprintf(fp1,"\n");
    }

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
