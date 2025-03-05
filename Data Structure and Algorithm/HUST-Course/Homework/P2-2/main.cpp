#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef  struct  Dnode
    {
        ElemType     data;
        struct  Dnode *prior,*next;
    } *DuLinkList;

#include "stu.h"
int main()
{
    FILE *fin = fopen("test1.in", "r");
    DuLinkList L,p,tail;
    int n,i;
    L=tail=(DuLinkList)malloc(sizeof(struct Dnode));
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
    {
        p=(DuLinkList)malloc(sizeof(struct Dnode));
        fscanf(fin,"%d",&p->data);
        tail->next=p;
        p->prior=tail;
        tail=p;
    }
    L->prior=tail;
    tail->next=L;
    //printf("The first number is %d\n",L->next->data);
    adjust(L);
    p=L->next;
    while(p!=L)
    {
        printf(" %d",p->data);
        p=p->next;
    }
}
