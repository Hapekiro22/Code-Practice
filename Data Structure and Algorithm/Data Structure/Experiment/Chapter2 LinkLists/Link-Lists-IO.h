//#include "def.h"

status SaveList(LinkList *L, char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if(*L == NULL)
        return INFEASIBLE;

    FILE *fout = fopen(FileName,"w");
    if(fout == NULL)
        return ERROR;

    LNode *temp = (*L)->next;
    while(temp != NULL)
    {
        fprintf(fout,"%d ",temp->data);
        temp = temp->next;
    }

    fclose(fout);
    return OK;

    /********** End 1 **********/
}

status LoadList(LinkList *L, char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if(*L != NULL)  // 如果链表已存在，返回INFEASIBLE
    {
        printf("Lists already exist, rewrite it? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if(choice != 'y' && choice != 'Y')
            return INFEASIBLE;  // 用户选择不重写
    }
    
    FILE *fin = fopen(FileName, "r");
    if(fin == NULL)
        return ERROR;
    
    // 创建头节点
    *L = (LinkList)malloc(sizeof(LNode));
    if(*L == NULL) {
        fclose(fin);
        return ERROR;
    }
    (*L)->next = NULL;
    
    LNode *tail = *L;  // 尾指针，用于尾插法
    int value;
    
    // 读取文件中的数据并创建链表节点
    while(fscanf(fin, "%d", &value) == 1)
    {
        LNode *newNode = (LNode*)malloc(sizeof(LNode));
        if(newNode == NULL) {
            fclose(fin);
            // 释放已分配的链表
            LNode *current = *L;
            while(current != NULL) {
                LNode *temp = current;
                current = current->next;
                free(temp);
            }
            *L = NULL;
            return ERROR;
        }
        
        newNode->data = value;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    
    fclose(fin);
    return OK;
    /********** End 2 **********/
}