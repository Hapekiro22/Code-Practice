
//---------------Lists-Initialization------------------//
status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)
    {
       // printf("Empty\n");
        L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
        return 1;
    }
    
    return -1;


    /********** End **********/
}


status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem != NULL)
    {
        int *noob = (int *)malloc(114514*sizeof(int));
        free(noob);
        L.elem = 0;
        return 1;
    }

    return -1;

    /********** End **********/
}

status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem != NULL)
    {
        L.length = 0;
        return 1;
    }

    return -1;

    /********** End **********/
}

//---------------Lists-Initialization---------------------//


//---------------List-check------------------------//

status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem != NULL)
        if(!L.length)
            return TRUE;
        else
            return FALSE;
    
    return -1;
    /********** End **********/
}

status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)
        return L.length;
    
    return -1;

    /********** End **********/
}

//---------------List-Empty-check------------------------//

//---------------List-Get-Operation---------------------------//
status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)
        if(i <= L.length && i >= 1)
        {
            e = *(L.elem + i - 1);
            return TRUE;
        }
        else
            return ERROR;

    return -1;

    /********** End **********/
}

int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)
    {
        int i = 0;
        while(i < L.length)
        {
            if(*(L.elem + i) == e)
                return (i + 1);
            i++;
        }
        return FALSE;
    }

    return -1;

    /********** End **********/
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)
    {
        int i = 1;
        while(i < L.length)
        {
            if(*(L.elem + i) == e)
            {
                pre = (*(L.elem + i - 1));
                return TRUE;
            }
                
            i++;
        }
        return FALSE;
    }

    return -1;

    /********** End **********/
}

status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
        if(L.elem)
    {
        int i = 0;
        while(i < L.length - 1)
        {
            if(*(L.elem + i) == e)
            {
                next = (*(L.elem + i + 1));
                return TRUE;
            }
                
            i++;
        }
        return FALSE;
    }

    return -1;

    /********** End **********/
}

status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
        if(L.elem)
    {
        if(i > 0 && i <= L.length)
        {
            int count = i - 1;
            e = *(L.elem + count);
            while(count < L.length - 1)
            {
                *(L.elem + count) = *(L.elem + count + 1);
                count++;
            }
            L.length--;
            return TRUE;
        }

        return FALSE;
        
    }

    return -1;


    /********** End **********/
}

//---------------List-Elem-Operation---------------------------//


//---------------Lists-Insert----------------------------------//
status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem)
    {
        if(L.length == L.listsize)
        {
            //printf("Current size is insufficient,the current length is %d, listsize is %d\n",L.length,L.listsize);
            L.elem = (ElemType *)realloc(L.elem, (L.listsize + LIST_INIT_SIZE) * sizeof(ElemType));            
            L.listsize += LIST_INIT_SIZE;
        }
        if(i > 0 && i <= L.length)
        {
            int count = L.length + 1;
            while(count > i)
            {
                *(L.elem + count - 1) = *(L.elem + count - 2);  
                count--;
            }
            *(L.elem + count - 1) = e;
            L.length++;
            return TRUE;
        }

        if(i == L.length + 1)
        {
            *(L.elem + i - 1) = e;
            L.length++;
            return TRUE;
        }

        return FALSE;
        
    }

    return -1;

    /********** End **********/
}


//---------------Lists-Insert----------------------------//

//---------------Lists-I/O----------------------------//
status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int idx = 0;
    if(L.elem)
    {
        for(idx = 0;idx < L.length;idx++)
        {
            if(idx != L.length - 1)
                printf("%d ",L.elem[idx]);
            else
                printf("%d",L.elem[idx]);
        }
            
        return OK;
    }

    return INFEASIBLE;

    /********** End **********/
}

status SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem != NULL)
    {
        FILE *fin = fopen(FileName, "w");
        int count = 0;
        for(count = 0; count < L.length; count++)
        {
            fprintf(fin ,"%d ", L.elem[count]);
        }

        fclose(fin);
        return OK;
    }

    return INFEASIBLE;
    /********** End **********/
}


status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(L.elem == NULL)
    {
        L.elem = (ElemType *)malloc(L.listsize * sizeof(ElemType));
        FILE *fout = fopen(FileName, "r");
        int count = 0;
        while (count < L.listsize && fscanf(fout, "%d", &L.elem[count]) == 1) {
            count++;
        }
        L.length = count;

        fclose(fout);
        return OK;
    }

    return INFEASIBLE;

    /********** End **********/
}
//---------------Lists-I/O----------------------------//

//---------------Multi-Lists-Operation------------------//
#include <string.h>

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int idx = Lists.length;
   // printf("idx=%d\n",idx);
    strcpy(Lists.elem[idx].name, ListName);

    Lists.elem[idx].L.elem = NULL;
    status init_err = InitList(Lists.elem[idx].L);

    Lists.length++;

    if(init_err != OK) return ERROR;
    return OK;
    /********** End **********/
}

#include <string.h>

status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int idx = 0;
    while(idx < Lists.length)
    {
        if(!strcmp(Lists.elem[idx].name, ListName))
            break;
        idx++;
    }

    if(idx == Lists.length) return ERROR;

    while(idx < Lists.length - 1)
    {
        strcpy(Lists.elem[idx].name, Lists.elem[idx+1].name);
        Lists.elem[idx].L.elem = Lists.elem[idx + 1].L.elem;
        Lists.elem[idx].L.length = Lists.elem[idx + 1].L.length;
        idx++;
    }

    Lists.length -= 1;

    return OK;

    /********** End **********/
}

int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int idx = 0;
    while(idx < Lists.length)
    {
        if(!strcmp(Lists.elem[idx].name, ListName))
            break;
        idx++;
    }

    if(idx == Lists.length) return 0;

    return idx + 1;

    /********** End **********/
}

//---------------Multi-Lists-Operation------------------//
