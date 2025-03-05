//函数countZero的功能是统计一串二级制数中最长的连续0的个数，并返回这一串0的结束位置和长度,用一个二元数组存储这些信息
//函数参数是一个int数组和数组长度
//函数ReverseNum是复制一个数组并将复制后的数组中的一段反转，返回反转后的数组
//函数cmpNumSeries是比较两个数组的大小，返回1表示第一个数组大，0表示相等，-1表示第二个数组大

#include <stdio.h>
#include <stdlib.h>
#define NUMLEN 200

int *ReverseNum(int *series,int start,int end)        //start和end是数组坐标(0,1,2,)
{
    int *nums = (int *)malloc(NUMLEN*sizeof(int));
    for(int i = 0;i < NUMLEN;i++)
        *(nums + i) = *(series + i);
    for(int i = start;i < ((start + end)/2 + 1);i++)
    {
        int temp = *(nums + i);
        *(nums + i) = *(nums + start + end - i);
        *(nums + start + end -i) = temp;
    }
    return nums;
}

int cmpNumSeries(int *series1,int *series2,int len)
{
    for(int i = 0;i < len;i++)
    {
        int gap = series1[i] - series2[i];
        if(gap > 0)
            return 1;
        if(gap < 0)
            return -1;
    }
}

int main()
{
    int *series = (int *)malloc(NUMLEN*sizeof(int));
    char c;
    int len = 0,maxZero = 0,step = 0,count = 0,c1 = 1,start;
    int maxGroup[NUMLEN][2];            //max,end
    while((c = getchar())!='\n')
    {
        *(series + (len++)) = (int)(c - '0');
        if(c1 && c == '1')
        {
            c1 = 0;
            start = len-1;            //start是1的位置
        }
    }
    /*if(len == 2 && *(series) == 0 && *(series + 1) == 1)
    {
        printf("01");
        return 0;
    }*/
    //printf("start:%d\n",start);
    int flag = 1;
    for(int i = 0;i < len;i++)
    {
        if(*(series + i) == 0)
        {
            step++;
            if(flag)
                flag = 0;
        }
        else if(*(series + i)==1 && (!flag))
        {
            if(step >= maxZero)
            {
                count++;
                maxZero = step;
                maxGroup[count-1][0] = maxZero;
                maxGroup[count-1][1] = i - 1;
            }
            step = 0;
            flag = 1;
        }
    }
    if(step >= maxZero)
    {
        count++;
        maxZero = step;
        maxGroup[count-1][0] = maxZero;
        maxGroup[count-1][1] = len - 1;
    }
    int i = 0;
    /*for(i = 0;i < count;i++)
        printf("%d %d\n",maxGroup[i][0],maxGroup[i][1]);*/
    for(i = 0;i < count && maxGroup[i][0] != maxZero;i++);
    int *minSeries = series;
    for(i;i < count;i++)
    {
        int *temp = ReverseNum(series,start,maxGroup[i][1]);
        //printf("Now try to reverse from %d to %d\n",start,maxGroup[i][1]);
        //printf("\n");
        if(cmpNumSeries(temp,minSeries,len) == -1)
        {
            minSeries = temp;
            //printf("Find a smaller one when reverse from %d to %d\n",start,maxGroup[i][1]);
        }
            
    }
    for(i = 0;i < len;i++)
        printf("%d",*(minSeries + i));
    return 0;
}
