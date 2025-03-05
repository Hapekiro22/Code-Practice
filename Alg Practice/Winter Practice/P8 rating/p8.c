//评分，去掉最高分和最低分，求平均分，保留两位小数

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int max = 0, min = 10;
    int sum = 0;
    for(int i = 0;i < n;i++)
    {
        int score;
        scanf("%d", &score);
        if(score > max)
            max = score;
        if(score < min)
            min = score;
        sum += score;
    }
    sum -= max;
    sum -= min;
    printf("%.2f\n", (float)sum / (n - 2));
    return 0;
}