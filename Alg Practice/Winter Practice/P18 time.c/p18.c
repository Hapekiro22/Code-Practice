//01串部分反转比较
#include <stdio.h>
#include <stdlib.h>
#define NUMLEN 101

int *ReverseNum(int *series,int start,int end)        //start和end是数组坐标(0,1,2,)
{
    int *nums = series;
    for(int i = start;i < ((start + end)/2);i++)
    {
        int temp = *(nums + start);
        *(nums + i) = *(nums + start + end - i);
        *(nums + start + end -i) = temp;
    }
    return;
}

int cmpNumSeries(int *series1,int *series2,int len)
{
    for(int i = 0;i < len;i++)
    {
        int gap = series1[i] - series2[i];
        if(gap > 0)
            return 1;
        if(gap == 0)
            return 0;
        if(gap < 0)
            return -1;
    }
}

int main()
{
    int *series = (int *)malloc(NUMLEN*sizeof(int));
    char c;
    int len = 0,maxZero = 0,step = 0,count = 0,start;
    int maxGroup[NUMLEN][3];            //max,start,end
    while((c = getchar())!='\n')
        *(series + (len++)) = (int)(c - '0');
    int flag = 1;
    for(int i = 0;i < len;i++)
    {
        if(*(series + i) == 0)
        {
            step++;
            if(flag)
            {
                count++;
                start = i;
                flag = 0;
            }
        }
        else if(*(series + i)==1 && (!flag))
        {
            if(step > maxZero)
            {
                maxZero = step;
                maxGroup[count-1][0] = maxZero;
                maxGroup[count-1][1] = start;
                maxGroup[count-1][2] = start + step;
            }
            flag = 1;
            step = 0;
        }
    }
    int i;
    for(i = 0;i < NUMLEN;i++)
    {
        if(maxGroup[i][0] == maxZero)
            break;
    }
    int *minSeries = series;
    for(;i < count;i++)
    {

    }

       
}