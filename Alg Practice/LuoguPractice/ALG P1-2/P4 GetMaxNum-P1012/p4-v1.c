//由于最高位直接决数的大小，所以直接贪心算法即可、
//能推导的就推导，不要过于暴力！！！
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_NUMLEN 11
#define MAX_BLOCK 20

typedef struct block
{
    int len;
    char numStr[MAX_NUMLEN + 1];
} block;


/*具体来说，用如下规则比较：
1.先按照正常的数位比较
2.如果数位不同且前几位相同，则比较较长数的最后一位和较短数的第一位的大小，我们希望较大的数尽可能提前的出现在高位
3.只用比较这几位数的原因是，当前情况下，尽可能早的高位数是从当前最佳的最高位中选出来的，
那么之后的最高位要么是第二个数的最高位，要么是第一个数的最后一位*/
int cmpBlock(block *a,block *b)
{
    char *str1 = a->numStr;
    char *str2 = b->numStr;
    int len1 = a->len;
    int len2 = b->len;
    int count = 0;
    for(;str1[count] != 0 && str2[count] != 0;count++)
    {
        if(str1[count] > str2[count])
        {
            return 1;
        }
        if(str1[count] < str2[count])
        {
            return -1;
        }
    }

    char end;
    if(len1 > len2)
    {
        end = str1[count];
        if(end > str2[0])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        end = str2[count];
        if(end > str1[0])
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }


}

int main()
{
    int n;
    scanf("%d",&n);
    block *blocks = (block *)malloc(n * sizeof(block));
    for(int i = 0;i < n;i++)
    {
        char num[MAX_NUMLEN + 1];
        scanf("%s",num);
        int len = strlen(num);
        blocks[i].len = len;
        strcpy(blocks[i].numStr,num);
    }

    for(int i = 0;i < n;i++)
    {
        for(int j = i + 1;j < n;j++)
        {
            if(cmpBlock(&blocks[i],&blocks[j]) < 0)
            {
                block temp = blocks[i];
                blocks[i] = blocks[j];
                blocks[j] = temp;
            }
        }
    }

    for(int i = 0;i < n;i++)
    {
        printf("%s",blocks[i].numStr);
    }
}