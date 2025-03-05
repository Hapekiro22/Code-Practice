//输入一个数字方阵，将每一行或每一列三个及以上相邻的数字变为0，直到没有三个及以上相邻的数字为止
#include<stdio.h>
#include<malloc.h>

void SearchNum(int **matrix,int row,int col);
void changeMatrix(int **matrix,int **MarkMatrix,int row,int col);
void PrintMatrix(int **matrix,int row,int col);

int main()
{
    int row,col;
    scanf("%d %d",&row,&col);
    int **matrix = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++) {
        matrix[i] = (int *)malloc(col * sizeof(int));
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    SearchNum(matrix,row,col);
    PrintMatrix(matrix,row,col);

    for(int i = 0; i < row; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void changeMatrix(int **matrix,int **MarkMatrix,int row,int col)   // 用标记矩阵对原矩阵做检查，值为0时将原矩阵改为0
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(MarkMatrix[i][j]==0) matrix[i][j] = 0;
        }
    }
}

void SearchNum(int **matrix,int row,int col)
{
    int i,j,k;
    int **MarkMatrix;                  //标记矩阵，标记是否有三个及以上相邻的数字
    MarkMatrix = (int **)malloc(row * sizeof(int *));
    for(int i = 0; i < row; i++) 
    {
        MarkMatrix[i] = (int *)malloc(col * sizeof(int));
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {           
            MarkMatrix[i][j] = 1;   //初始化标记矩阵，值为1
        }
    }
    int checknum,step;             //记录当前数字,当前路径步数
    for(i=0,j=0;i<row;)            //按行搜索
    {
        checknum = matrix[i][j];
        step = 1;
        while(j + step < col && matrix[i][j + step] == checknum) step++;     //检查当前数字右边是否有相同数字
        if(step>=3)
        {
            for(k=0;k<step;k++)
            {
                MarkMatrix[i][j+k] = 0;
            }
        }
        j+=step;
        if(j>col-3) {j = 0;i++;}      //移动到下一个数字
    }

    for(i=0,j=0;j<col;)         //按列搜索
    {
        checknum = matrix[i][j];
        step = 1;
        while(i + step < row && matrix[i + step][j] == checknum) step++;
        if(step>=3)
        {
            for(int k=0;k<step;k++)
            {
                MarkMatrix[i+k][j] = 0;
            }
        }
        i+=step;
        if(i>row-3) {i = 0;j++;}                //移动到下一个数字
    }

    changeMatrix(matrix,(int **)MarkMatrix,row,col);
}
void PrintMatrix(int **matrix,int row,int col)
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
}