#include<stdio.h>
#include<stdlib.h>

typedef struct c_node{
    char data;  struct c_node *next;
} C_NODE;

//给定一串字符，建立一个链表，判断该链表是否是回文链表。
void createLinkList(C_NODE **headp, char s[]) 
{
    C_NODE *loc_head = NULL;
    C_NODE *tail = NULL;
    if(s[0] == '\0') return;
    else
    {
        loc_head = (C_NODE *)malloc(sizeof(C_NODE));
        loc_head->data = *s++;
        tail = loc_head;
        while(*s)
        {
            tail->next = (C_NODE *)malloc(sizeof(C_NODE));
            tail = tail->next;
            tail->data = *s++;
        }
        tail->next = NULL;
    }
    *headp = loc_head;
}

void PrintLinkList(C_NODE *head)
{
    C_NODE *p = head;
    while(p)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}

void judgePalindrome(C_NODE *head)
{
    C_NODE *p = head;
    int len = 0;
    for(; p; p = p->next) len++; //计算链表长度
    int half = len/2;
    char *s = (char *)malloc(half); 
    p = head;
    for(int i = 0; i < half; i++)
    {
        s[i] = p->data;
        p = p->next;
    }
    if(len % 2 == 1) p = p->next;
    for(int i = half - 1; i >= 0; i--)
    {
        if(s[i] != p->data)
        {
            printf("false\n");
            return;
        }
        p = p->next;    
    }
    printf("true\n");
}

int main()
{
    char str[] = "abccba";
    C_NODE *head = NULL;
    createLinkList(&head, str);
    judgePalindrome(head);
    return 0;
}