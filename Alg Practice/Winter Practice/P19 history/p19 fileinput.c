//局部字符串比较

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 9000

int main()
{
    char S[LENGTH], T[LENGTH];
    FILE *fp = fopen("history/history9.in", "r");
    fscanf(fp, "%s", S);
    fscanf(fp, "%s", T);
    int q;
    fscanf(fp, "%d", &q);
    for(int i = 0;i < q;i++)
    {
        int ls,rs,lt,rt;
        fscanf(fp, "%d %d %d %d", &ls, &rs, &lt, &rt);
        int len1 = rs - ls + 1, len2 = rt - lt + 1;         //计算长度
        char *subS = (char *)malloc(sizeof(char) * (len1+1));
        char *subT = (char *)malloc(sizeof(char) * (len2+1));
        for(int j = 0;j < len1;j++)
            subS[j] = S[ls + j-1];
        subS[len1] = '\0';
        for(int j = 0;j < len2;j++)
            subT[j] = T[lt + j-1];
        subT[len2] = '\0';
        //printf("subS:%s, subT:%s\n", subS, subT);
        if(strcmp(subS, subT) == 0)
            printf("ovo\n");
        else if(strcmp(subS, subT) < 0)
            printf("yifusuyi\n");
        else
            printf("erfusuer\n");
    }
    return 0;
}