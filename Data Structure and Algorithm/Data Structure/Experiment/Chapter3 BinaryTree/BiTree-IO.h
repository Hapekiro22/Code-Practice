// 全局文件指针
FILE *g_outFile = NULL;

// 节点访问函数
void SaveNode(BiTree node)
{
    if(node == NULL)
        fprintf(g_outFile, "0 null  ");
    else
        fprintf(g_outFile, "%d %s  ", node->data.key, node->data.others);
}

status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    // 打开文件
    FILE *fout = fopen(FileName,"w");
    if(fout == NULL)
        return ERROR;

    // 设置全局文件指针
    g_outFile = fout;
    
    // 使用先序遍历保存节点
    PreOrderTraverse(T, SaveNode);
    
    // 关闭文件
    fclose(fout);
    return OK;
}

status LoadBiTree(BiTree *T, char FileName[])  // 修改为指针参数

{
    FILE *fin = fopen(FileName, "r");
    if(fin == NULL)
        return ERROR;

    TElemType definition[128]; // 假设最多128个节点
    int i = 0;
    do {
        fscanf(fin,"%d%s",&definition[i].key,definition[i].others);
    } while (definition[i++].key!=-1);
    fclose(fin);
 
    // 重新构建二叉树
    *T = NULL;  // 使用指针访问
    CreateBiTree_Pre(T, definition);  // 直接传递指针
    //printf("%d %s\n", (*T)->lchild->data.key, (*T)->lchild->data.others); // 输出根节点信息

    return OK;
}