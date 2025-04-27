//#include "def.h"

status InitList(LinkList *L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL)
    {
        *L = (LNode *)malloc(sizeof(LNode));
        (*L) -> next = NULL;
        return OK;
    }
    
    return INFEASIBLE;
    /********** End **********/
}

status DestroyList(LinkList *L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L != NULL)
    {
        LNode *start = *L;
        LNode *temp = *L;
        while((*L) -> next != NULL)
        {
            *L = (*L) -> next;
            free(temp);
            temp = *L;
        }
        *L = NULL;
        free(temp);
        return OK;
    }

    return INFEASIBLE;
    /********** End **********/
}

status ClearList(LinkList *L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL) {
        return INFEASIBLE;  // 链表不存在
    }
    
    LNode *p = (*L)->next;  // p指向第一个数据节点
    LNode *temp;
    
    while(p != NULL) {
        temp = p;         // 保存当前节点
        p = p->next;      // p移动到下一个节点
        free(temp);       // 释放当前节点
    }
    
    (*L)->next = NULL;    // 头节点的next指针置为NULL
    return OK;
    /********** End **********/
}

status ListEmpty(LinkList *L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL)
        return INFEASIBLE;

    if((*L) -> next == NULL)
        return TRUE;
    
    return FALSE;
    /********** End **********/
}

int ListLength(LinkList *L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL)
        return INFEASIBLE;
    
    int length = 0;
    LNode *temp = *L;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
        length++;
    }

    return length;
    /********** End **********/
}

status GetElem(LinkList *L, int i, ElemType *e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL)
        return INFEASIBLE;
    
    LNode * temp = *L;
    int count = 0;
    while(temp -> next != NULL && count < i)
    {
        temp = temp -> next;
        count++;
    }

    if(count < i - 1 || count == 0) return ERROR;

    *e = temp -> data;

    return OK;
    /********** End **********/
}

status LocateElem(LinkList *L, ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL)
        return INFEASIBLE;

    int idx = 0;
    LNode *temp = *L;
    while(temp != NULL)
    {
        if(temp -> data == e)
            return idx; 
        temp = temp -> next;
        idx++;
    }

    if(temp -> data != e)
        return ERROR;
    
    return ERROR;  // 补充返回值
    /********** End **********/
}

status PriorElem(LinkList *L, ElemType e, ElemType *pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL)
        return INFEASIBLE;
    
    // 如果链表为空(仅有头节点)
    if((*L)->next == NULL)
        return ERROR;
        
    LNode *current = (*L)->next;
    LNode *prior = *L;
    
    while(current != NULL)
    {
        if(current->data == e && prior != *L)
        {
            *pre = prior->data;
            return OK;
        }
        prior = current;
        current = current->next;
    }
    
    // 如果没找到元素e或元素e是第一个元素(无前驱)
    return ERROR;
    /********** End **********/
}

status NextElem(LinkList *L, ElemType e, ElemType *next)
// 如果线性表L存在，获取线性表L中元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL)
        return INFEASIBLE;
    
    // 如果链表为空(仅有头节点)
    if((*L)->next == NULL)
        return ERROR;
        
    LNode *current = (*L)->next;
    
    while(current != NULL)
    {
        // 找到元素e
        if(current->data == e)
        {
            // 检查是否有后继
            if(current->next != NULL)
            {
                *next = current->next->data;
                return OK;
            }
            else
            {
                // 元素e是最后一个元素，没有后继
                return ERROR;
            }
        }
        current = current->next;
    }
    
    // 没有找到元素e
    return ERROR;
    /********** End **********/
}

status ListInsert(LinkList *L, int i, ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*L == NULL)
        return INFEASIBLE;
    
    int count = 0;
    LNode *prior = *L;
    LNode *current = (*L) -> next;
    while(current != NULL && count < i - 1)
    {
        prior = current;
        current = current -> next;
        count++;
    }

    if(count != i - 1) return ERROR;

    LNode *insert = (LNode *)malloc(sizeof(LNode));
    insert -> data = e;
    prior -> next = insert;
    insert -> next = current;
    return OK;
    /********** End **********/
}

status ListDelete(LinkList *L, int i, ElemType *e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // 检查链表是否存在
    if(*L == NULL)
        return INFEASIBLE;
    
    // 检查删除位置是否合法
    if(i <= 0)
        return ERROR;
    
    int count = 0;
    LNode *prior = *L;  // 从头节点开始
    
    // 定位到第i-1个位置
    while(prior != NULL && count < i-1)
    {
        prior = prior->next;
        count++;
    }
    
    // 检查定位是否成功以及要删除的位置是否有效
    if(prior == NULL || prior->next == NULL)
        return ERROR;  // i大于链表长度或链表为空
    
    // 删除节点
    LNode *current = prior->next;  // 要删除的节点
    prior->next = current->next;
    
    // 保存被删除节点的数据
    *e = current->data;
    
    // 释放节点内存
    free(current);
    return OK;
    /********** End **********/
}