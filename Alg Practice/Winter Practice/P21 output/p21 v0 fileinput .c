#include <stdio.h>
#include <stdlib.h>

int *BinaryFactor(unsigned num)
{
    int len,len1 = 0;
    for(len = 0;num >> len;len++);
    int *factor = (int *)malloc((len + 1)*sizeof(int));     //第一位是因子个数，后面的是因子
    *factor = len;
    //printf("num = %u,len = %d\n",num,len);
    for(int i = len-1;i >= 0;i--)
    {
        if(num & (1 << i))
        {
            *(factor + (len - i)) = i;
            len1++;
        }
            
        else 
            *(factor + (len - i)) = -1;
    }
    int *factorExist = (int *)malloc((len1+1)*sizeof(int));
    *factorExist = len1;
    for(int i = 1,j = 1;i < len + 1;i++)
    {
        if(*(factor + i) != -1)
            *(factorExist + (j++)) = *(factor + i);
    }
    return factorExist;                                     //将数组压缩,第一位仍然是长度
}

void BinaryOutput(int *factor)
{
    int len = *factor,flag = 0;
    for(int i = 1;i < len + 1;i++)
        if(*(factor + i) != 0 || *(factor + i) != 1 || *(factor + i) != 2)
            flag = 1;
    //printf("flag = %d\n",flag);
    if(!flag) return;
    for(int i = 1;i < len + 1;i++)
    {
        if(*(factor + i) == 0)
            printf("2(0)");
        else if(*(factor + i) == 1)
            printf("2");
        else if(*(factor + i) == 2)
            printf("2(2)");
        else
        {
            printf("2(");
            BinaryOutput(BinaryFactor(*(factor + i)));
            printf(")");
        }
        if(i != len) printf("+");
    }

}

int main()
{
    FILE *fp;
    fp = fopen("output/output5.in","r");
    unsigned int num;
    fscanf(fp,"%u",&num);
    int *factor = BinaryFactor(num);
    //for(int i = 1;i < *factor + 1;i++) printf("%d  ",*(factor + i)); 
    BinaryOutput(factor);
    printf("\n");

    free(factor);          
    return 0;
}