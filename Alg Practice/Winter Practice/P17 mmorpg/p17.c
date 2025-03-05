//链表的指定删除
//构造一个地点列表，地点名称由字母和数字组成，地点名称不重复，名称按照字典序排列
//列表用链表存储，用首字符作为关键字，按照字典序排列
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define STRINGLEN 15
#define DICLEN 75           //方便起见，中间空出来几个

typedef struct Location
{
    char *name;
    char indexc;
    struct Location *next;
}Location;

Location **CreateDictionary();
void LinkXSeries(Location *index, char x,char *word);
void DeleteNode(Location *index, char x, char *word);
void SortNode(Location *LocList);
void PrintList(Location *LocList);

int main()
{
    long n,m,k;
    scanf("%ld %ld %ld",&n,&m,&k);
    Location **LocList = CreateDictionary();        //0~9,A~Z,a~z: 0->0, A->17, a->49
    for(int i = 0;i < n;i++)
    {
        char *word = (char *)malloc(STRINGLEN*sizeof(char));
        scanf("%s",word);
        char x = *word;
        LinkXSeries(*(LocList + x - '0'),x,word);
    }
    Location *p = *LocList;

    for(int i = 0;i < m;i++)
    {
        char *word = (char *)malloc(STRINGLEN*sizeof(char));
        scanf("%s",word);
        char x = *word;
        DeleteNode(*(LocList + x - '0'),x,word);
    }
    for(int i = 0;i < k;i++)
    {
        char *word = (char *)malloc(STRINGLEN*sizeof(char));
        scanf("%s",word);
        char x = *word;
        LinkXSeries(*(LocList + x - '0'),x,word);
    }
    SortNode(*LocList);    
    for(int i = 1;i < DICLEN;i++)
    {
        for(;p -> next != NULL;p = p->next);
        p -> next = *(LocList + i);
    }
    PrintList(*LocList);
    free(LocList);

    return 0;
}

Location **CreateDictionary()
{
    Location **LocList = (Location **)malloc(DICLEN*sizeof(Location *));
    for(int i = 0;i < DICLEN;i++)
    {
        *(LocList + i) = (Location *)malloc(sizeof(Location));
        Location *p = *(LocList + i);
        p -> name = (char *)malloc(sizeof(char));
        strcpy(p -> name,"\0");
        if(((i > 9)&&(i < 17)) || ((i > 42)&&(i < 49)))
            p -> indexc = '\0';
        else p -> indexc = (char)(i + '0');
        p -> next = NULL;
    }
    return LocList;
}

void LinkXSeries(Location *index, char x,char *word)
{
    Location *p = index;
    for(;p -> next != NULL;p = p -> next);
    p -> next = (Location *)malloc(sizeof(Location));
    p = p->next;
    p -> indexc = x;
    p -> name = (char *)malloc(STRINGLEN*sizeof(char));
    strcpy(p -> name,word);
    p -> next = NULL;
}

void DeleteNode(Location *index, char x, char *word)
{
    Location *p = index -> next;
    Location *q = index;
    for(;p -> indexc == x;p = p -> next,q = q -> next)
    {
        if(!strcmp(word,p -> name))
        {
            q -> next = p -> next;
            return;
        }  
    }
}

void SortNode(Location *LocList)
{
    Location *p = LocList;
    for(;p -> next != NULL;p = p -> next)
    {
        Location *q = p -> next;
        for(;q != NULL;q = q -> next)
        {
            if(strcmp(p -> name,q -> name) > 0)
            {
                char *temp = p -> name;
                p -> name = q -> name;
                q -> name = temp;
            }
        }
    }
}

void PrintList(Location *LocList)
{
    //printf("The list is:\n");
    Location *p = LocList;
    for(;p != NULL;p = p -> next)
    {
        if(p -> name[0] != '\0')
        printf("%s\n",p -> name);
    }
}

