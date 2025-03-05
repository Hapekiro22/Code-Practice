//构造一个n*n的顺转方阵
#include<stdio.h>
#include<malloc.h>

void SpiralMatrix(int **matrix,int n);
void PrintMatrix(int **matrix,int n);

int main()
{
    int n;
    scanf("%d",&n);
    int **Matrix=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        Matrix[i]=(int *)malloc(n*sizeof(int));
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            Matrix[i][j]=0;
        }
    }                                   //初始化矩阵,在SpriralMatrix中会用到
    
    SpiralMatrix(Matrix,n);
    PrintMatrix(Matrix,n);

    for (int i = 0; i < n; i++) 
    {
        free(Matrix[i]);
    }
    free(Matrix);

    return 0;
}

void SpiralMatrix(int **matrix,int n)
{
    int count = 0,arrow = 0;                   //count记录总共走了几次，arrow记录当前方向
    int i,j;
    //int way_count = n
    for(i=0,j=0;count<n*n;)
    {                  
        switch(arrow%4)                                                           //方向只有4个，所以取模4
        {
            case 0 :while(j<n && matrix[i][j]==0) {matrix[i][j++] = count+1;count+=1;}    //向右走，直到碰到边界或已经走过的地方
                    if((j>=n)||(matrix[i][j]!=0)) {j--;arrow++;i++;} break;                                               //走到头后要回退一步
            case 1 : while(i<n && matrix[i][j]==0) {matrix[i++][j] = count+1;count+=1;}    //向下走
                    if((i>=n)||(matrix[i][j]!=0)) {i--;arrow++;j--;} break;
            case 2 : while(j>=0 && matrix[i][j]==0) {matrix[i][j--] = count+1;count+=1;}   //向左走
                    if((j<0)||(matrix[i][j]!=0)) {j++;arrow++;i--;} break;
            case 3 : while(i>=0 && matrix[i][j]==0) {matrix[i--][j] = count+1;count+=1;}   //向上走
                    if((i<0)||(matrix[i][j]!=0)) {i++;arrow++;j++;} break;
        }
    }

}

void PrintMatrix(int **matrix,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==n-1) printf("%d",matrix[i][j]);
            else
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}