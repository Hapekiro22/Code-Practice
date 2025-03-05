//日期结构体
#include <stdio.h>
#include <stdlib.h>

struct date
{
    int year;
    int month;
    int day;
};

int main()
{
    int monthday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    struct date d;
    scanf("%d %d %d", &d.year, &d.month, &d.day);
    if(d.month>12||monthday[d.month-1]<d.day||d.day<1)
    {
        printf("不存在这样的日期\n");
        return 0;
    }
    int gap = 0;
    if(d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0)
        gap = 1;
    int sum = 0;   //计算这是该年的第几天
    for(int i = 0; i < d.month - 1; i++)
    {
        sum += monthday[i];
    }
    sum += d.day;
    if(d.month > 2)
        sum += gap;
    printf("%d\n", sum);
}
