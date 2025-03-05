//模块化编程，成绩处理，将成绩按照从高到低的顺序排列，如果成绩相同，则按照字典序排列
//添加功能4 成绩查找，用二分查找找出所有成绩为num的学生，输出学生姓名和成绩
#include <stdio.h>
#include<malloc.h>
#include<string.h>
#define CHECK 400

void rankScore(int *score,char **name);
void printScore(int *score,char **name);
void searchScore(int *score,char **name,int check,int num);  
void swap(char **str1,char **str2);

int main()
{
    int mode,num;
    int score[1000] = {CHECK}; 
    for (int i = 0; i < 1000; i++) {
        score[i] = CHECK;
    }
    char *name[1000] = {NULL};
    void (*modeselect[2])(int *,char **)={rankScore,printScore};
    do
    {
        scanf("%d",&mode);
        if(mode==1)
        {
            scanf("%d",&num);
            for (int i = 0; i < num; i++)
            {
                name[i] = malloc(100);
                scanf("%s %d",name[i],&score[i]);
            }
        }
        if((mode<=3&&mode>=2))
        {
            (*modeselect[mode-2])(score,name);
        }
        if(mode==4)
        {
            int check;
            scanf("%d",&check);
            searchScore(score,name,check,num);
        }
    } while (mode);

    for (int i = 0; i < 1000 && name[i] != NULL; i++) {
        free(name[i]);
    }

    return 0;
    
}

void swap(char **str1,char **str2)
{
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void rankScore(int *score,char **name)
{
    int i,j,temp;
    for(i=0;score[i]!=CHECK;i++)
    {
        char tempn[10000];
        for(j=i+1;score[j]!=CHECK;j++)
        {
            if(score[j]>score[i])
            {
                temp = score[i];
                score[i] = score[j];
                score[j] = temp;    
                swap(&name[i],&name[j]);
            }
            if(score[j]==score[i])                                          //分数相同，按字典序排序
            {
                if(strcmp(name[j],name[i])<0)   swap(&name[i],&name[j]);
            }
        }
    }
    return;
}

void printScore(int *score,char **name)
{
    int i;
    for(i=0;i<1000;i++)
    {
        if(score[i]!=CHECK)
            printf("%s %d\n",name[i],score[i]);
        else break;
    }
    return;
}

void searchScore(int *score,char **name,int check,int num)
{
    int mid,left,right,lstep=1,pass=0;
    rankScore(score,name);
    for(left=0,right=num-1;left<=right;mid=(left+right)/2)
    {
        if(score[mid]==check) 
        {
            pass=1;                                         //找到成绩
            while(score[mid-lstep]==check)
            {
                lstep++;                                    //找到一个成绩，如果前面还有相同的成绩，就左移
            }
            mid-=lstep-1;                                   //找到顺序下第一个成绩              
            while(score[mid]==check)
            {
                printf("%s %d\n",name[mid],score[mid]);     //从左向右输出指定成绩
                mid++;
            }
            break;
        }
        if(score[mid]>check) right = mid - 1;               //如果成绩大于指定成绩，就向左移
        if(score[mid]<check) left = mid + 1;                //如果成绩小于指定成绩，就向右移
    }
    if(!pass) printf("not found\n");
}