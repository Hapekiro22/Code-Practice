//数组的查找和替换
//暴力查找版本

#include <stdio.h>
#include <stdlib.h>

typedef struct NotePage
{
    struct NotePage *next;
    int TheoryNum;
}NotePage;


int SearchNum(NotePage *Note,int m,int num)
{
    NotePage *p = Note;
    for(int i = 0;i < m;i++)
    {
        if(p->TheoryNum == num)
        {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int CheckCount(NotePage *Note, int *TheoryList, int m, int n)
{
    int count = 0,i,j;
    NotePage *first = Note, *replace = Note;
    for(j = 0;j < m;i++)
    {
        if(!SearchNum(Note,m,TheoryList[i]))
        {
            count++;
            first->TheoryNum = TheoryList[i];
            first = first->next;
            //printf("Theory %d is not in the note,add it\n",TheoryList[i]);
            j++;
        }
    }//先把笔记本填满
    for(;i<n;i++)
    {
        if(!SearchNum(Note,m,TheoryList[i]))
        {
            count++;
            //printf("Theory %d is not in the note,add it and replace the theory %d\n",TheoryList[i],replace->TheoryNum);
            replace->TheoryNum = TheoryList[i];
            replace = replace->next;
        }
    }//替换笔记本
    return count;
}

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int *TheoryList = (int *)malloc(sizeof(int) * n);
    for(int i = 0;i < n;i++)
        scanf("%d",&TheoryList[i]);
    //创建一个环形链表，作为空白笔记本
    NotePage *Note = (NotePage*)malloc(sizeof(NotePage));
    NotePage *head = Note;     
    for(int i = 0;i < m-1;i++)
    {
        Note->TheoryNum = -1;
        Note->next = (NotePage*)malloc(sizeof(NotePage));
        Note = Note->next;
    }
    Note->TheoryNum = -1;
    Note->next = head; // 最后一个节点指向头节点，形成环形链表

    printf("%d\n",CheckCount(Note,TheoryList,m,n));
    return 0;
}


