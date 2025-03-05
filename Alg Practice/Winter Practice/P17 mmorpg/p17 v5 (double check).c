//链表的指定删除
//构造一个地点列表，地点名称由字母和数字组成，地点名称不重复，名称按照字典序排列
//列表用链表存储，用前两个字符作为关键字，按照字典序排列,空间换时间
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define STRINGLEN 15
#define ROW 75
#define DICLEN 5625           //方便起见，中间空出来几个

typedef struct Location
{
    char *name;
    char indexc[2];
    struct Location *next;
}Location;

Location **CreateDictionary();
void LinkXSeries(Location *index, char x[2],char *word);
void DeleteNode(Location *index, char x[2], char *word);
void SortNode(Location **LocList);
void PrintList(Location *LocList);
void PrintDictionary(Location **LocList);

int main()
{
    long n,m,k;
    scanf("%ld %ld %ld",&n,&m,&k);
    Location **LocList = CreateDictionary(); 
    char *word = (char *)malloc(STRINGLEN*sizeof(char));       //0~9,A~Z,a~z: 0->0, A->17, a->49
    for(int i = 0;i < n;i++)
    {
        scanf("%s",word);
        char x[2];
        if(strlen(word) == 1)
        {
            x[0] = *word;
            x[1] = '\0';
        }
        else
        {
            x[0] = *word;
            x[1] = *(word + 1);
        }
        long gap = (x[0] - '0')*ROW + (x[1] - '0');
        LinkXSeries(*(LocList + gap),x,word);
    }
    for(int i = 0;i < m;i++)
    {
        scanf("%s",word);
               char x[2];
        if(strlen(word) == 1)
        {
            x[0] = *word;
            x[1] = '\0';
        }
        else
        {
            x[0] = *word;
            x[1] = *(word + 1);
        }
        long gap = (x[0] - '0')*ROW + (x[1] - '0');
        DeleteNode(*(LocList + gap),x,word);
    }
    for(int i = 0;i < k;i++)
    {
        scanf("%s",word);
        char x[2];
        if(strlen(word) == 1)
        {
            x[0] = *word;
            x[1] = '\0';
        }
        else
        {
            x[0] = *word;
            x[1] = *(word + 1);
        }
        long gap = (x[0] - '0')*ROW + (x[1] - '0');
        LinkXSeries(*(LocList + gap),x,word);
    }
    //PrintDictionary(LocList);
    SortNode(LocList);
    Location *p = *LocList;
    //printf("////////////////////////////////////////////////////////////////////////////////////\n");
    for(int i = 1;i < DICLEN;i++)
    {
        for(;p -> next != NULL;p = p->next);
        p -> next = *(LocList + i);
    }                                               //将各个序列连接起来            
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
        p -> indexc[0] = (char)(i/ROW + '0');
        p -> indexc[1] = (char)(i%ROW + '0');
        p -> next = NULL;
    }
    return LocList;
}

void LinkXSeries(Location *index, char x[2],char *word)
{
    Location *p = index;
    for(;p -> next != NULL;p = p -> next);
    p -> next = (Location *)malloc(sizeof(Location));
    p = p->next;
    p -> indexc[0] = x[0];
    p -> indexc[1] = x[1];
    p -> name = (char *)malloc(STRINGLEN*sizeof(char));
    strcpy(p -> name,word);
    p -> next = NULL;
}

void DeleteNode(Location *index, char x[2], char *word)
{
    Location *p = index -> next;
    Location *q = index;
    for(;p!=NULL;p = p -> next,q = q -> next)
    {
        //printf("           check %s with %s\n",word,p -> name);
        if(!strcmp(word,p -> name))
        {
            q -> next = p -> next;
            return;
        }  
    }
}

 void quickSort(Location **arr, long left, long right)
    {
        if(left < right)
        {
            long pivotIndex = left + (right - left) / 2;
            Location *pivot = arr[pivotIndex];
            long l = left;
            long r = right;
            while(l <= r)
            {
                while(strcmp(arr[l]->name, pivot->name) < 0)
                    l++;
                while(strcmp(arr[r]->name, pivot->name) > 0)
                    r--;
                if(l <= r)
                {
                    Location *temp = arr[l];
                    arr[l] = arr[r];
                    arr[r] = temp;
                    l++;
                    r--;
                }
            }
            if(left < r)
                quickSort(arr, left, r);
            if(l < right)
                quickSort(arr, l, right);
            }
        }


void SortNode(Location **LocList)
{
    for(int i = 0; i < DICLEN; i++)
    {
        Location *p = (*(LocList + i))->next;
        if(p == NULL)
            continue;
        Location **arr = (Location **)malloc(110000 * sizeof(Location *));
        long j;
        for(j = 0; j < 110000; j++)
        {
            if(p == NULL)
                break;
            arr[j] = p;
            p = p->next;
        }
        j--;
        quickSort(arr, 0, j);
        (*(LocList + i))->next = arr[0];
        for(long k = 0; k < j; k++)
            arr[k]->next = arr[k + 1];
        arr[j]->next = NULL;

        free(arr);
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

void PrintDictionary(Location **LocList)
{
    for(int i = 0;i < DICLEN;i++)
    {
        Location *p = *(LocList + i);
        printf("series %c:\n",i + '0');
        for(;p != NULL;p = p -> next)
        {
            if(p -> name[0] != '\0')
            printf("\t%s\n",p -> name);
        }
    }
}

