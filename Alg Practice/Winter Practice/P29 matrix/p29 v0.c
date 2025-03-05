#include <stdio.h>
#include <stdlib.h>
#define LIMITS 998244353
#define ROW 3
#define COL 3
#define MAXLEN 100

unsigned long long **mulMatrix(unsigned long long **matrix1,unsigned long long **matrix2,int row);       //仅作方阵乘法
int *BinaryNumber(unsigned long long num,int *len);              //第一位存长度
void limitMatrix(unsigned long long **matrix);
void printMatrix(unsigned long long **matrix,int row,int col);
void printBinary(int *binnum,int len);

int main()
{
    FILE *fp = fopen("matrix/matrix02.in","r");
    unsigned long long n,f1,f2,a,b,c;
    fscanf(fp,"%llu",&n);
    fscanf(fp,"%llu %llu",&f1,&f2);
    fscanf(fp,"%llu %llu %llu",&a,&b,&c);
    unsigned long long **matrix = (unsigned long long **)malloc(ROW*sizeof(unsigned long long *));
    for(int i = 0;i < ROW;i++)
    {
        matrix[i] = (unsigned long long *)malloc(COL*sizeof(unsigned long long));
    }
    matrix[0][0] = a,matrix[0][1] = b,matrix[0][2] = 1;
    matrix[1][0] = 1,matrix[1][1] = 0,matrix[1][2] = 0;
    matrix[2][0] = 0,matrix[2][1] = 0,matrix[2][2] = 1;

    int len = 0;
    int *binnum = BinaryNumber(n-2,&len);
    printBinary(binnum,len);
    
    unsigned long long ***multipliedMatrix = (unsigned long long ***)malloc(len*sizeof(unsigned long long **));
    *multipliedMatrix = matrix;
    unsigned long long **p = matrix;
    for(int i = 1;i < len;i++)
    {
        *(multipliedMatrix + i) = mulMatrix(p,p,ROW);
        limitMatrix(*(multipliedMatrix + i));
        p = *(multipliedMatrix + i);
    }                                                   //第i个是A^(2^(i-1))
    for(int i = 0;i < len;i++)
    {
        printf("A^(2^%d):\n",i);
        printMatrix(*(multipliedMatrix + i),ROW,COL);
        printf("\n");
    }

    unsigned long long **result = NULL;
    unsigned long long **I = (unsigned long long **)malloc(ROW*sizeof(unsigned long long *));//单位矩阵
    for(int i = 0;i < ROW;i++)
        I[i] = (unsigned long long *)malloc(COL*sizeof(unsigned long long));
    for(int i = 0;i < ROW;i++)
    {
        for(int j = 0;j < ROW;j++)
        {
            if(i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;
        }
    }

    result = I;
    for(int i = 0;i < len;i++)
    {
        if(*(binnum + i))
        {
            result = mulMatrix(result,*(multipliedMatrix + i),ROW);
            limitMatrix(result);
            printMatrix(result,ROW,COL);
        }
    }
    unsigned long long fn = (result[0][0]*f2 + result[0][1]*f1 + result[0][2]*c) % LIMITS;
    printf("%lld\n",fn);

    free(matrix);
    free(binnum);
    free(multipliedMatrix);
    return 0;
}

unsigned long long **mulMatrix(unsigned long long **matrix1,unsigned long long **matrix2,int row)
{
    unsigned long long result[ROW][ROW] = {0};
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < row;j++)
        {
            for(int k = 0;k < row;k++)
            {
                result[i][j] += matrix1[i][k]*matrix2[k][j];        //矩阵乘法
            }
        }
    }
    unsigned long long **resultMatrix = (unsigned long long **)malloc(row*sizeof(unsigned long long *));
    for(int i = 0;i < row;i++)
    {
        resultMatrix[i] = (unsigned long long *)malloc(row*sizeof(unsigned long long));
        for(int j = 0;j < row;j++)
        {
            resultMatrix[i][j] = result[i][j];
        }
    }
    return resultMatrix;
}

int *BinaryNumber(unsigned long long num,int *len)
{
    int binnum0[MAXLEN] = {0};
    int mask = 1;
    while(num)
    {
        binnum0[*len] = num&mask;
        num >>= 1;
        (*len)++;
    }
    int *binnum = (int *)malloc((*len)*sizeof(int));
    printf("len = %d\n",*len);
    for(int i = 0;i < *len;i++)
    {
        binnum[i] = binnum0[i];
    }
    return binnum;
}

void limitMatrix(unsigned long long **matrix)
{
    for(int i = 0;i < ROW;i++)
    {
        for(int j = 0;j < COL;j++)
        {
            matrix[i][j] %= LIMITS;
        }
    }
}

void printMatrix(unsigned long long **matrix,int row,int col)
{
    for(int i = 0;i < row;i++)
    {
        for(int j = 0;j < col;j++)
        {
            printf("%lld ",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printBinary(int *binnum,int len)
{
    printf("The number in binary is: ");
    printf("The length is: %d\n",len);
    for(int i = 0;i < len;i++)
    {
        printf("%d",binnum[i]);
    }
    printf("\n");
}