#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MODE1 11
#define MODE2 21
#define WIN 'W'
#define LOSE 'L'
#define END 'E'
#define LEN 62505

void MatchResult(int mode,char *process)
{
    int score1 = 0,score2 = 0;
    int flag = 1,end = 0;
    for(int i = 0;i < strlen(process);i++)
    {
        end = 0;
        if(process[i] == WIN) score1++;
        else if(process[i] == LOSE) score2++;
        //printf("Round %d:  %d:%d\n",i,score1,score2);
        if(score1 >= mode && flag || score2 >= mode && flag)
        {
            printf("%d:%d\n",score1,score2);
            score1 = 0;
            score2 = 0;
            end = 1;
        }
        if(score1 == mode - 1 && score2 == mode - 1) flag = 0;
        if(flag == 0 && abs(score1 - score2) >= 2)
        {
            printf("%d:%d\n",score1,score2);
            score1 = 0;
            score2 = 0;
            flag = 1;
            end = 1;
        }
    }
    if(1) printf("%d:%d\n",score1,score2);
    return;
}

int main()
{
    char c;
    char process[LEN];
    long i = 0;
    for(i = 0;(c = getchar()) != END;i++)
    {
        if(c == '\n') {i--;continue;}
        process[i] = c;
    }
    process[i] = '\0';
    MatchResult(MODE1,process);
    printf("\n");
    MatchResult(MODE2,process);

    return 0;
}