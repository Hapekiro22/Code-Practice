#include <stdlib.h>
#include<stdio.h>

typedef struct str_node {
    char ch;
    struct str_node *next;
} TLONG_STR, *PLONG_STR;

void creat(PLONG_STR head);
void out(PLONG_STR head);
int  long_str_len(PLONG_STR first);

int main()
{
    PLONG_STR p, head = (PLONG_STR)malloc(sizeof(TLONG_STR));
    char *pch;
    long len;
    int i;
    
    creat(head);
    out(head);
	putchar('\n');
    len = long_str_len( head->next);
    pch = (char *)malloc(len+1);
    for (i=0,p=head->next; p!=NULL; p=p->next)
        pch[i++] = p->ch;
    pch[i] = '\0';
printf("%s\n", pch);

    return 0;
}

void creat(PLONG_STR head)
{
    PLONG_STR tail = head;
    char ch;
    
    while ((ch=getchar()) != EOF) {
        tail->next = (PLONG_STR)malloc(sizeof(TLONG_STR));
        tail = tail->next;   ;
        tail->ch = ch;
    }
    tail->next = NULL;
}

void out(PLONG_STR head)
{
    PLONG_STR p;
    
    for (p=head->next; p!=NULL  ; p=p->next)
        putchar(p->ch);
    putchar('\n');
}

int  long_str_len(PLONG_STR first)
{
    if (first == NULL)
        return 0;
    return 1 + long_str_len(first->next);   ;
}
