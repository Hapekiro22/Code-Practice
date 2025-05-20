
status InitBiTrees(BiTrees &T)
{
    T.num = 0; // 初始化二叉树数量为0
    for (int i = 0; i < INIT_TREE_NUM; i++) {
        T.Trees[i] = NULL; // 初始化每棵树为空
        strcpy(T.name[i], ""); // 初始化名称为空字符串
    }
    return OK;
}

status ClearBiTrees(BiTrees &T)
{
    for (int i = 0; i < T.num; i++) {
        ClearBiTree(&T.Trees[i]); // 清空每棵树
    }
    T.num = 0; // 重置二叉树数量为0
    return OK;
}

status AddBiTree(BiTrees &T, char name[])
{
    if (T.num >= INIT_TREE_NUM) return ERROR; 
    T.Trees[T.num] = NULL; 
    strcpy(T.name[T.num], name); 
    T.num++; 
    return OK;
}

int LocateBiTree(BiTrees T, char name[])
{
    for (int i = 0; i < T.num; i++) {
        if (strcmp(T.name[i], name) == 0) return i; 
    }
    return -1; 
}

status DeleteBiTree(BiTrees &T, char name[])
{
    int index = LocateBiTree(T, name); 
    if (index == -1) return ERROR; 
    ClearBiTree(&T.Trees[index]); // 清空树
    for (int i = index; i < T.num - 1; i++) {
        T.Trees[i] = T.Trees[i + 1]; // 移动树
        strcpy(T.name[i], T.name[i + 1]); // 移动名称
    }
    T.num--; // 减少数量
    return OK;
}

status PrintBiTrees(BiTrees T)
{
    for (int i = 0; i < T.num; i++) {
        printf("Tree %d: %s\n", i + 1, T.name[i]); 
    }
    return OK;
}


