//函数countZero的功能是统计一串二级制数中最长的连续0的个数，并返回这一串0的结束位置和长度,用一个二元数组存储这些信息
//函数参数是一个int数组和数组长度
//函数ReverseNum是复制一个数组并将复制后的数组中的一段反转，返回反转后的数组
//函数cmpNumSeries是比较两个数组的大小，返回1表示第一个数组大，0表示相等，-1表示第二个数组大
//做好输入检查
#include <stdio.h>
#include <stdlib.h>
#define NUMLEN 200

int *ReverseNum(int *series, int start, int end)        //start和end是数组坐标(0,1,2,)
{
    if (start < 0 || end >= NUMLEN || start > end) {
        return NULL; // 返回NULL表示参数无效
    }
    int *nums = (int *)malloc(NUMLEN * sizeof(int));
    if (nums == NULL) {
        return NULL; // 返回NULL表示内存分配失败
    }
    for (int i = 0; i < NUMLEN; i++) {
        *(nums + i) = *(series + i);
    }
    for (int i = start; i < ((start + end) / 2 + 1); i++) {
        int temp = *(nums + i);
        *(nums + i) = *(nums + start + end - i);
        *(nums + start + end - i) = temp;
    }
    return nums;
}

int cmpNumSeries(int *series1, int *series2, int len)
{
    if (len > NUMLEN) {
        return 0; // 返回0表示参数无效
    }
    for (int i = 0; i < len; i++) {
        int gap = series1[i] - series2[i];
        if (gap > 0)
            return 1;
        if (gap < 0)
            return -1;
    }
    return 0;
}

int main()
{
    int *series = (int *)malloc(NUMLEN * sizeof(int));
    if (series == NULL) {
        return 0; // 返回1表示内存分配失败
    }
    char c;
    int len = 0, maxZero = 0, step = 0, count = 0, c1 = 1, start;
    int maxGroup[NUMLEN][2];            //max,end
    FILE *fp = fopen("time/time3.in","r");
    while ((c = fgetc(fp)) != EOF && len < NUMLEN) {
        if (c == '0' || c == '1')
            *(series + (len++)) = (int)(c - '0');
        if (c1 && c == '1') {
            c1 = 0;
            start = len - 1;            //start是1的位置
        }
    }
    //printf("start:%d\n", start);
    int flag = 1;
    for (int i = 0; i < len; i++) {
        if (*(series + i) == 0) {
            step++;
            if (flag)
                flag = 0;
        } else if (*(series + i) == 1 && (!flag)) {
            if (step >= maxZero) {
                if (count < NUMLEN) {
                    maxZero = step;
                    maxGroup[count][0] = maxZero;
                    maxGroup[count][1] = i - 1;
                    count++;
                }
            }
            step = 0;
            flag = 1;
        }
    }
    if (step >= maxZero) {
        if (count < NUMLEN) {
            maxZero = step;
            maxGroup[count][0] = maxZero;
            maxGroup[count][1] = len - 1;
            count++;
        }
    }
    int i = 0;
    for (i = 0; i < count && maxGroup[i][0] != maxZero; i++);
    int *minSeries = series;
    for (; i < count; i++) {
        int *temp = ReverseNum(series, start, maxGroup[i][1]);
        if (temp == NULL) {
            //printf("NULL\n");
            continue; // 跳过无效的反转操作
        }
        if (cmpNumSeries(temp, minSeries, len) == -1) {
            if (minSeries != series) {
                free(minSeries);
            }
            minSeries = temp;
        } else {
            free(temp);
        }
    }
    for (i = 0; i < len; i++) {
        printf("%d", *(minSeries + i));
    }
    if (minSeries != series) {
        free(minSeries);
    }
    fclose(fp);
    free(series);
    return 0;
}