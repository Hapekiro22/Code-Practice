//#include "def.h"

status InitSequenceLists(LinkList *L)
{
    LNode *temp = *L;
    
    if(*L == NULL)
    {
        *L = (LinkList)malloc(sizeof(LNode));
        if(*L == NULL)
            return OVERFLOW;
        (*L)->next = NULL;
    }
    
    ElemType e = 0;
    while(scanf("%d", &e) == 1 && e != 0)
    {
        LNode *newNode = (LNode *)malloc(sizeof(LNode));
        if(newNode == NULL)
            return OVERFLOW;
        newNode->data = e;
        newNode->next = NULL;
        (*L)->next = newNode;
        (*L) = newNode; // 更新尾指针
    }

    (*L)->next = NULL; // 结束链表
    *L = temp; // 恢复头指针
    return OK;
}

status printLists(LinkList *L)
{
    if(*L == NULL)
        return INFEASIBLE;
    
    LNode *temp = (*L)->next;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return OK;
}


status reverseList(LinkList *L)
{
    if(*L == NULL)
        return INFEASIBLE;
    
    LNode *current = (*L)->next->next; // 从第一个数据节点开始
    LNode *prev = (*L)->next;
    LNode *next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next; 
    }

    (*L)->next->next = NULL;
    (*L)->next = prev; 

    return OK;
}

int DeleteNodefromEnd(LinkList *L, int n)
{
    //返回倒数第n个节点的值

    if(*L == NULL || (*L)->next == NULL)
        return INFEASIBLE;
    
    LNode *current = (*L)->next;
    LNode *fast = (*L)->next;
    for(int count = 0; count < n && fast != NULL; count++)
    {
        fast = fast->next;
    }

    if(fast == NULL)
        return ERROR; // n大于链表长度

    while(fast != NULL)
    {
        current = current->next;
        fast = fast->next;
    }

    ElemType e = current->data; // 倒数第n个节点的值
    LNode *temp = current->next; // 保存要删除的节点
    current->next = current->next->next; // 删除节点
    free(temp); // 释放内存

    return e; 
}

status SortList(LinkList *L)
{
    if(*L == NULL || (*L)->next == NULL)
        return INFEASIBLE;
    
    LNode *current = (*L)->next;
    LNode *next = NULL;
    LNode *sorted = NULL;

    while(current != NULL)
    {
        next = current->next; // 保存下一个节点
        if(sorted == NULL || sorted->data >= current->data) // 插入到头部
        {
            current->next = sorted;
            sorted = current;
        }
        else // 插入到中间或尾部
        {
            LNode *temp = sorted;
            while(temp->next != NULL && temp->next->data < current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next; // 继续处理下一个节点
    }

    (*L)->next = sorted; // 更新头指针

    return OK;
}