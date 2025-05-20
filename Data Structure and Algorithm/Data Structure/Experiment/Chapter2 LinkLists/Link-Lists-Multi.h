
status InitMultiLists(LISTS *Lists)
// 初始化Lists，创建一个空的线性表Lists，返回OK，否则返回INFEASIBLE。
{

    Lists->elem = (LinkList *)malloc(sizeof(LinkList) * MAX_LISTS_NUM);
    Lists->name = (char **)malloc(sizeof(char *) * MAX_LISTS_NUM);
    for(int i = 0; i < MAX_LISTS_NUM; i++)
    {
        Lists->elem[i] = NULL;
        Lists->name[i] = (char *)malloc(sizeof(char) * 20); // 假设每个列表名称不超过20个字符
    }
    if(Lists->elem == NULL)
        return INFEASIBLE;
    
    Lists->length = 0;
    Lists->listsize = MAX_LISTS_NUM;
    
    return OK;
}

status DestroyMultiLists(LISTS Lists)
{
    // 销毁Lists，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
    if(Lists.elem == NULL)
        return INFEASIBLE;
    
    for(int i = 0; i < Lists.length; i++)
    {
        DestroyList(&Lists.elem[i]);
    }
    
    free(Lists.elem);
    Lists.elem = NULL;
    
    return OK;
}

status CheckDuplicate(LISTS Lists, char *ListName)
{
    // 检查Lists中是否存在名称为ListName的线性表，存在返回TRUE，否则返回FALSE
    if(Lists.elem == NULL)
        return INFEASIBLE;
    
    for(int i = 0; i < Lists.length; i++)
    {
        if(strcmp(Lists.name[i], ListName) == 0)
            return TRUE;
    }
    
    return FALSE;
}

status AddList(LISTS *Lists, char *ListName)
{
    
    if(Lists->elem == NULL)
        return INFEASIBLE;
    
    if(Lists->length == MAX_LISTS_NUM)
        return OVERFLOW;

    //check if the list name already exists
    if(CheckDuplicate(*Lists, ListName) == TRUE)
        return ERROR;
    
    printf("Add the list %s, list id: %d\n", ListName, Lists->length + 1);   
    strcpy(Lists->name[Lists->length] ,ListName);
    InitList(&Lists->elem[Lists->length]);
    Lists->length++;

    return OK;
}

status RemoveList(LISTS *Lists, char *ListName)
{
    // 删除Lists中一个名称为ListName的线性表
    if(Lists->elem == NULL)
        return INFEASIBLE;
    
    int idx = 0;
    while(idx < Lists->length)
    {
        if(strcmp(Lists->name[idx], ListName) == 0)
            break;
        idx++;
    }
    
    if(idx == Lists->length)
        return ERROR;
    
    DestroyList(&Lists->elem[idx]);
    
    for(int i = idx; i < Lists->length - 1; i++)
    {
        strcpy(Lists->name[i], Lists->name[i + 1]);
        Lists->elem[i] = Lists->elem[i + 1];
    }
    
    Lists->length--;
    Lists->elem[Lists->length] = NULL; // 清空最后一个元素的指针
    return OK;
}

int LocateList(LISTS Lists, char *ListName)
{
    // 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
    if(Lists.elem == NULL)
        return INFEASIBLE;
    
    int idx = 0;
    while(idx < Lists.length)
    {
        if(strcmp(Lists.name[idx], ListName) == 0)
            break;
        idx++;
    }
    
    if(idx == Lists.length && strcmp(Lists.name[idx], ListName) != 0)
        return ERROR;
    
    return idx; 
}

void PrintLists(LISTS Lists)
{
    // 打印所有线性表的名称
    if(Lists.elem == NULL)
    {
        printf("No lists exist!\n");
        return;
    }
    
    for(int i = 0; i < Lists.length; i++)
    {
        printf("List %d: %s\n", i + 1, Lists.name[i]);
    }

    return;
}