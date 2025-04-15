#include "Def.h"
#include "Lists.h"

#define UPPER 1000000
#define LOWER -1000000

int MaxSubArray(SqList L);
int SubArrayNum(SqList L, int k);
void SortList(SqList L);

//计算线性表L的最大子序列和
int MaxSubArray(SqList L)
{
    if(L.elem == NULL) return ERROR;
    if(L.length == 0) return 0;

    int length = L.length;
    int *sub_sum = (int *)malloc(sizeof(int) * (length + 1));
    int max_sum = LOWER, min_sum = UPPER;

    //生成前缀和
    sub_sum[0] = L.elem[0];
    for(int i = 1; i < length; i++)
    {
        sub_sum[i] = sub_sum[i - 1] + L.elem[i];
        max_sum = max_sum < sub_sum[i] ? sub_sum[i] : max_sum;
        min_sum = min_sum > sub_sum[i] ? sub_sum[i] : min_sum;
    }

    free(sub_sum);
    return max_sum - min_sum;
}

//计算和为k的子数组个数
int SubArrayNum(SqList L, int k)
{
    if(L.elem == NULL) return ERROR;
    if(L.length == 0) return 0;

    int length = L.length;
    int *sub_sum = (int *)malloc(sizeof(int) * (length + 1));
    int count = 0;

    //生成前缀和
    sub_sum[0] = L.elem[0];
    for(int i = 1; i < length; i++)
        sub_sum[i] = sub_sum[i - 1] + L.elem[i];

    for(int i = 0; i < length; i++)
        for(int j = i + 1; j < length; j++)
            if(sub_sum[j] - sub_sum[i] == k)
                count++;

    free(sub_sum);
    return count;
}

//顺序表排序
void SortList(SqList L)
{
    if(L.elem == NULL)
    {
        fprintf(stderr, "Error: List is NULL\n");
        return;
    }

    for(int i = 0; i < L.length - 1; i++)
    {
        for(int j = i + 1; j < L.length; j++)
        {
            if(L.elem[i] > L.elem[j])
            {
                int temp = L.elem[i];
                L.elem[i] = L.elem[j];
                L.elem[j] = temp;
            }
        }
    }
}



