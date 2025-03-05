#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    FILE *fpout = fopen("change/change1.out","r");
    FILE *fpans = fopen("change/change1.ans","r");
    FILE *fp = fopen("change/change0.in","w");
    //比较两个文件的内容
    char *ans = (char *)malloc(100*sizeof(char));
    char *out = (char *)malloc(100*sizeof(char));
    long long count = 1,flag = 1;
    while(fscanf(fpout,"%s",out) != EOF)
    {
        fscanf(fpans,"%s",ans);
        if(strcmp(ans,out) != 0)
        {
            flag = 0;
            printf("In line %lld, the %lld number is wrong: ",((count + 1)/2),(count + 1)%2 + 1);
            printf("out = %s,ans = %s\n",out,ans);
            //printf("The input number can be found in line %lld!\n",count + );
        }
        count++;
    }

    if(flag)
        printf("All right!\n");
    fclose(fpout);
    fclose(fpans);
    return 0;
}