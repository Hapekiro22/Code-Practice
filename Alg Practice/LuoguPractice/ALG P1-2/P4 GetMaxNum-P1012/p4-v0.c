//相同位数的数排序
//不同位数的数进行DFS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_NUMLEN 11
#define MAX_BLOCK 20
#define NONE -1
#define DEBUG 1

typedef struct block
{
    int len;
    long long num;
} block;

void printList(block **blocks);

long long maxNum = 0;
void dfs(block **blocks, long long curNum,int count,int *curLoc);

int main()
{
    int n;
    scanf("%d",&n);
    block **blocks = (block **)malloc(MAX_NUMLEN * sizeof(block *));
    for (int i = 0; i < MAX_NUMLEN; i++)
    {
        blocks[i] = (block *)malloc(MAX_BLOCK * sizeof(block));
        for(int j = 0; j < MAX_BLOCK; j++)
        {
            blocks[i][j].len = NONE;
            blocks[i][j].num = NONE;
        }
    }

    int countLen[MAX_NUMLEN] = {0};
    //读入数据,并按照位数存储
    for(int i = 0;i < n;i++)
    {
        char num[MAX_NUMLEN + 1];
        scanf("%s",num);
        int len = strlen(num);
        //printf("len = %d\n",len);
        blocks[len][countLen[len]].len = len;
        blocks[len][countLen[len]].num = atoll(num);
        countLen[len]++;
        //printf("num = %lld\n",blocks[len][countLen[len] - 1].num);
    }
    printList(blocks);

    //相同位数的数排序
    for(int i = 1;i < MAX_NUMLEN;i++)
    {
        if(blocks[i][0].len == NONE)
        {
            continue;
        }
        for(int j = 0;j < countLen[i] - 1;j++)
        {
            for(int k = j + 1;k < countLen[i];k++)
            {
                if(blocks[i][j].num < blocks[i][k].num)
                {
                    long long temp = blocks[i][j].num;
                    blocks[i][j].num = blocks[i][k].num;
                    blocks[i][k].num = temp;
                }
            }
        }
    }

    //初始化
    long long curNum = 0;
    int count = n;
    int *curLoc = (int *)malloc(MAX_NUMLEN * sizeof(int));
    for(int i = 0;i < MAX_NUMLEN;i++)
    {
        curLoc[i] = 0;
    }

    dfs(blocks,curNum,count,curLoc);
    printf("%lld",maxNum);

    for (int i = 0; i < MAX_NUMLEN; i++)
    {
        free(blocks[i]);
    }
    free(blocks);
    free(curLoc);
    return 0;
}

void dfs(block **blocks, long long curNum,int count,int *curLoc)
{
    if(count == 0)
    {
        if(curNum > maxNum)
        {
            maxNum = curNum;
        }
        return;
    }
    for(int i = 1;i < MAX_NUMLEN;i++)
    {
        if(blocks[i][*(curLoc + i)].num == NONE)
        {
            continue;
        }                                               //当前位数没有数

        int tempLoc = *(curLoc + i);
        *(curLoc + i) = tempLoc + 1;
        long long tempNum = blocks[i][tempLoc].num;     //保存当前数
        curNum = curNum * pow(10,i) + tempNum;          //增加一个数到当前数的末尾
        count--;                                        //减少一个数

        if(DEBUG)
        {
            if(count == 19)
            printf("Now curNum = %lld, try to add %lld\n",curNum,tempNum);
        }

        dfs(blocks,curNum,count,curLoc);
        count++;                                        //回溯
        curNum = (curNum - tempNum) / pow(10,i);        
        *(curLoc + i) = tempLoc;                        
    }
    return;
}

void printList(block **blocks)
{
    for (int i = 0; i < MAX_NUMLEN; i++)
    {
        if(blocks[i][0].len == NONE)
        {
            continue;
        }
        printf("In group %d: ",i);
        for (int j = 0; ;j++)
        {
            if(blocks[i][j].num == NONE)
            {
                break;
            }
            printf("%lld  ",blocks[i][j].num);
        }
        printf("\n");
    }
    return;
}