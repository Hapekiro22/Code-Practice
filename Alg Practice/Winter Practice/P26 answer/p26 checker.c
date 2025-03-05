#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIMIT 200000

int main()
{
    FILE *fout = fopen("answer/answer10.out","r");
    FILE *fans = fopen("answer/answer10.ans","r");
    int flag = 0;
    for(int i = 0;!feof(fout) && !feof(fans);i++)
    {
        int out,ans;
        fscanf(fout,"%d",&out);
        fscanf(fans,"%d",&ans);
        if(out != ans)
        {
            printf("Wrong answer at Line %d:",i);
            printf("Output = %d, Answer = %d\n",out,ans);
            flag++;
        }
    }
    if(!flag) printf("Accepted!\n");
    else printf("There are %d wrong answers\n",flag);
    fclose(fout);
    fclose(fans);
    return 0;
}