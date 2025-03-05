#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fout = fopen("binary/binary19.out","r");
    FILE *fans = fopen("binary/binary19.ans","r");
    int out,ans;
    long long i = 0;
    int flag = 0;
    while(fscanf(fout,"%d",&out) != EOF)
    {
        fscanf(fans,"%d",&ans);
        if(out != ans && out != 0)
        {
            printf("Wrong answer at line %lld :",i);
            printf("out = %d, ans = %d\n",out,ans);
            flag++;
        }
        i++;
    }
    if(!flag)
        printf("Correct\n");
    else 
        printf("Total %d wrong answers\n",flag);
    return 0;
}