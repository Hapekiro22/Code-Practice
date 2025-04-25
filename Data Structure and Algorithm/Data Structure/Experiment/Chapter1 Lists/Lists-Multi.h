#include <string.h>

//---------------Multi-Lists-Operation------------------//

status AddList(LISTS *Lists, char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int idx = Lists->length;
   // printf("idx=%d\n",idx);
    strcpy(Lists->elem[idx].name, ListName);

    Lists->elem[idx].L.elem = NULL;
    status init_err = InitList(&Lists->elem[idx].L);

    Lists->length++;

    if(init_err != OK) return ERROR;
    return OK;
    /********** End **********/
}

status RemoveList(LISTS *Lists, char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int idx = 0;
    while(idx < Lists->length)
    {
        if(!strcmp(Lists->elem[idx].name, ListName))
            break;
        idx++;
    }

    if(idx == Lists->length) return ERROR;

    while(idx < Lists->length - 1)
    {
        strcpy(Lists->elem[idx].name, Lists->elem[idx+1].name);
        Lists->elem[idx].L.elem = Lists->elem[idx + 1].L.elem;
        Lists->elem[idx].L.length = Lists->elem[idx + 1].L.length;
        idx++;
    }

    Lists->length -= 1;

    return OK;

    /********** End **********/
}

int LocateList(LISTS *Lists, char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int idx = 0;
    while(idx < Lists->length)
    {
        if(!strcmp(Lists->elem[idx].name, ListName))
            break;
        idx++;
    }

    if(idx == Lists->length) return 0;

    return idx ;

    /********** End **********/
}

void ShowList(LISTS *Lists)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int idx = 0;
    while(idx < Lists->length)
    {
        printf("%s ",Lists->elem[idx].name);
        idx++;
    }
    printf("\n");

    /********** End **********/
}


//---------------Multi-Lists-Operation------------------//