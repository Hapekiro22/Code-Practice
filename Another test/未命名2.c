//����countZero�Ĺ�����ͳ��һ�������������������0�ĸ�������������һ��0�Ľ���λ�úͳ���,��һ����Ԫ����洢��Щ��Ϣ
//����������һ��int��������鳤��
//����ReverseNum�Ǹ���һ�����鲢�����ƺ�������е�һ�η�ת�����ط�ת�������
//����cmpNumSeries�ǱȽ���������Ĵ�С������1��ʾ��һ�������0��ʾ��ȣ�-1��ʾ�ڶ��������

#include <stdio.h>
#include <stdlib.h>
#define NUMLEN 200

int *ReverseNum(int *series,int start,int end)        //start��end����������(0,1,2,)
{
    int *nums = malloc(NUMLEN*sizeof(int));
    int i;
    for(i = 0;i < NUMLEN;i++)
        *(nums + i) = *(series + i);
    for(i = start;i < ((start + end)/2 + 1);i++)
    {
        int temp = *(nums + i);
        *(nums + i) = *(nums + start + end - i);
        *(nums + start + end -i) = temp;
    }
    return nums;
}

int cmpNumSeries(int *series1,int *series2,int len)
{
	int i;
    for(i = 0;i < len;i++)
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
            start = len-1;            //start��1��λ��
        }
    }
    if(len == 2 && *(series) == 0 && *(series + 1) == 1)
    {
        printf("01");
        return 0;
    }
    //printf("start:%d\n",start);
    int flag = 1;
    int i;
    for(i = 0;i < len;i++)
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
    i = 0;
    for(;i < count && maxGroup[i][0] != maxZero;i++);
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
        
    int den;
    scanf("%d",&den);
    return 0;
}

