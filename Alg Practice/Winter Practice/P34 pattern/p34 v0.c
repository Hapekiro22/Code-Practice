//矩阵压缩方法进行矩阵比较
//暂时采用行压缩方法
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define LEN 8           //矩阵的长度
#define BASE 13         //压缩的基数,来自于可输入的字符串的种类
#define MAX 100         //最大的矩阵数  
#define NONE -1         //标记目录为空

void printRow(long long *row)
{
    printf("The compressed row is: ");
    for (int i = 0; i < LEN; i++)
    {
        printf("%lld ", row[i]);
    }
    printf("\n");
}

void printMatrix(char **matrix)
{
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//可输入的字符串有*,B,K,N,R,Q,P,b,k,n,r,q,p
//对应的分数为0,1,2,3,4,5,6,7,8,9,10,11,12
void stringTranslate(char *str)
{
    int count = 0;
    for (int i = 0; i < LEN; i++)
    {
        switch(str[i])
        {
            case '*':
            str[i] = 0;
            break;
            case 'B':
            str[i] = 1;
            break;
            case 'K':
            str[i] = 2;
            break;
            case 'N':
            str[i] = 3;
            break;
            case 'R':
            str[i] = 4;
            break;
            case 'Q':
            str[i] = 5;
            break;
            case 'P':
            str[i] = 6;
            break;
            case 'b':
            str[i] = 7;
            break;
            case 'k':
            str[i] = 8;
            break;
            case 'n':
            str[i] = 9;
            break;
            case 'r':
            str[i] = 10;
            break;
            case 'q':
            str[i] = 11;
            break;
            case 'p':
            str[i] = 12;
            break;
        }
    }
    return;
}

long long base[LEN] = {0};
void initBase()
{
    base[0] = 1;
    for (int i = 1; i < LEN; i++)
    {
        base[i] = base[i - 1] * BASE;
    }
}

//矩阵压缩，压缩成一个1*8的行矩阵,压缩成一个数太大
//BASE为压缩的基数
long long *matrixCompress(char **matrix)
{
    long long *result = (long long *)malloc(LEN*sizeof(long long));
    for(int i = 0;i < LEN;i++)
        result[i] = 0;
    for(int i = 0;i < LEN;i++)
    {
        for(int j = 0;j < LEN;j++)
        {
            result[i] += matrix[i][j] * base[j];
        }
    }
    return result;
}

bool matrixCmp(long long *matrix1, long long *matrix2)
{
    for(int i = 0;i < LEN;i++)
    {
        if(matrix1[i] != matrix2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FILE *fin = fopen("pattern/pattern23.in", "r");
    FILE *fout = fopen("pattern/pattern23.out", "w");
    initBase();                                         //初始化base数组
    int n;
    fscanf(fin, "%d", &n);
    int count[MAX] = {0};
    int record[MAX] = {0};
    long long **rowMatrix = (long long **)malloc(n * sizeof(long long *));
    for(int i = 0;i < n;i++)
    {
        rowMatrix[i] = (long long *)malloc(LEN * sizeof(long long));
        rowMatrix[i][0] = NONE;
    }

    char **temp = (char **)malloc(LEN * sizeof(char *));
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < LEN;j++)
        {
            char *str = (char *)malloc(LEN * sizeof(char));
            fscanf(fin,"%s",str);
            //printf("The string is: %s\n",str);
            stringTranslate(str);
            temp[j] = str;
        }
        //printMatrix(temp);

        long long *CompressedMatrix = matrixCompress(temp);
        //printRow(CompressedMatrix);
        for(int j = 0;j < n;j++)
        {
            if(rowMatrix[j][0] == NONE)
            {
                rowMatrix[j] = CompressedMatrix;
                count[j]++;
                record[i] = count[j];
                break;
            }
            else if(matrixCmp(rowMatrix[j],CompressedMatrix))
            {
                count[j]++;
                record[i] = count[j];
                //fprintf(fout,"%d\n",count[j]);
                break;
            }
        }
    }
    free(temp);
    fclose(fin);

    for(int i = 0;i < n;i++)
    {
        fprintf(fout,"%d\n",record[i]);
    }

    fclose(fout);
    free(rowMatrix);
    return 0;
}
