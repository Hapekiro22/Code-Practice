//这是输出检查程序
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fout = fopen("pattern/pattern23.out","r");
    FILE *fans = fopen("pattern/pattern23.ans","r");
    int count = 1,flag = 1;
    while(!feof(fout) && !feof(fans))
    {
        int out,ans;
        fscanf(fout,"%d",&out);
        fscanf(fans,"%d",&ans);
        if(out != ans)
        {
            printf("Wrong Answer in line %d: ",count);
            printf("out: %d,ans: %d\n",out,ans);
            flag = 0;
        }
        count++;
    }
    if(flag)
    {
        printf("Accepted!\n");
    }
    fclose(fout);
    fclose(fans);
    return 0;
}