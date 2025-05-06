#include "BiTree-Traverse.h"

// 全局文件指针
FILE *g_outFile = NULL;

// 节点访问函数
void SaveNode(BiTree node)
{
    fprintf(g_outFile, "%d %s\n", node->data.key, node->data.others);
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

status LoadBiTree(BiTree &T, char FileName[])  
{
    FILE *fin = fopen(FileName, "r");
    if(fin == NULL)
        return ERROR;

    TElemType definition[128]; // 假设最多128个节点
    int i = 0;
    while(fscanf(fin, "%d %s", &definition[i].key, definition[i].others) != EOF)
    {
        i++;
    }
    fclose(fin);

    // 重新构建二叉树
    T = NULL;
    CreateBiTree(T, definition);

    return OK;
}