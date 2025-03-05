//改进的Joseph问题解决方法，采用数组标记
#include<stdio.h>
#include<malloc.h>

void JosephSolve(int n,int len);

int main()
{
    int n,len;
    scanf("%d %d",&len,&n);     //输入总人数以及淘汰序号
    JosephSolve(n,len);
    return 0;
    
}

void JosephSolve(int n,int len)
{    
    int *row = (int *)malloc(len * sizeof(int)),i;       //定义一个数组，用于标记是否被淘汰
    if (row == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    for(i=0;i<len;i++) row[i]=1;                         //数组初始化

    int count,num=0,sum=0; 
    while(sum<len-1)  
    {
        for(count=1;count<=n;num++)
        {
            num = num%len;
            if(row[num]!=0) count++;                   //如果这个人未被淘汰，则报数
        }                                              //找到第n个未被淘汰的人
        row[num-1] = 0;
        sum++;
    }                                                   
    
    for(i=0;i<len;i++)
        if(row[i]) printf("%d ",i+1);

    free(row);
    return;
}