//（1）用一个单向链表接收一个长字符串，且每个节点接收一个字符，遍历输出链表中的所有字符，
//并将字符串无冗余地存放到一个动态存储分配的的字符数组中，并且输出该字符串。（本题暂不考虑空字符串情况）(结尾以回车结束)
//（2）再输入一个字符，如果该字符已在链表中，则删除该结点，
//否则在输入字符和结点的数据域字符差值最小的结点后面插入包含该字符的结点，输出最后的字符串。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *former;
    struct Node *next;
} Node;

int CreateList(struct Node **head);                              //创建链表,返回链表长度
Node **checkList(struct Node *head, char c,int len);             //检查链表中是否有指定字符，并返回一个指向该字符的指针数组
Node *insertNode(struct Node *head, char c,int len);            //在指定结点后插入一个结点
Node *deleteNode(struct Node *head, char c, Node **p,int len);            //删除指定结点
void printList(struct Node *head);
void loadList(struct Node *head, char *str);

int main()
{
    struct Node *head =NULL;
    char *str = malloc(CreateList(&head) * sizeof(char));
    char c;
    scanf("%c", &c);
    loadList(head, str);
    printList(head);
    printf("%s\n", str);
    Node **p = checkList(head, c, strlen(str));
    if(*p != NULL)
        head = deleteNode(head, c, p, strlen(str));
    else
        head = insertNode(head, c, strlen(str));
    loadList(head, str);
    printf("%s\n", str);
    return 0;
}

int CreateList(struct Node **head)
{
    char c;
    scanf("%c", &c);
    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->data = c;
    (*head)->next = NULL;
    (*head)->former = NULL;
    struct Node *p = *head;
    int len = 1;
    while(1)
    {
        scanf("%c",&c);
        if(c=='\n')     break;
        struct Node *q = (struct Node*)malloc(sizeof(struct Node));
        q->data = c;
        q->former = p;
        q->next = NULL;
        p->next = q;
        p = q;
        len++;
    }
    return len;
}

Node **checkList(struct Node *head, char c,int len)
{
    Node **p = (Node **)malloc(len*sizeof(Node *));         //指向目标字符的指针数组,最多有len个
    for(int i = 0; i < len; i++)
        p[i] = NULL;                                        //初始化为NULL
    Node *q = head;
    for(int i=0;(q->next)!=NULL;)
    {
        if(q->data==c)
        {
            *(p+i) = q;
            i++;
        }
        q = q->next;
    }
    return p;
}

Node *insertNode(struct Node *head, char c,int len)               //在与c差值最小的点后插入c
{
    Node *p = head;
    int min = abs(p->data - c);
    for(int i = 0; p != NULL; i++)
    {
        if(abs(p->data - c) < abs(min - c))
        {
            min = p->data;
        }
        p = p->next;
    }
    p = head;
    for(int i=0;i<len;i++)
    {
        if(p->data==min)
        {
            Node *q = (struct Node*)malloc(sizeof(struct Node));
            q->data = c;
            q->next = p->next;
            p->next = q;           
        }
        p = p->next;
    }
    return head;
}

Node *deleteNode(struct Node *head, char c, Node **p, int len)
{
    for(int i=0;(*(p+i))!=NULL;i++)
    {
        if(*(p+i)==head)
        {
            head = head->next;
            free(*(p+i));
        }
        else
        {
            Node *q = (*(p+i))->former;
            q->next = (*(p+i))->next;
            free(*(p+i));
        }
    }
    return head;
}

void printList(struct Node *head)
{
    Node *p = head;
    while(p != NULL)
    {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

void loadList(struct Node *head, char *str)
{
    Node *p = head;
    int i = 0;
    while(p != NULL)
    {
        str[i] = p->data;
        i++;
        p = p->next;
    }
    str[i] = '\0';
}

