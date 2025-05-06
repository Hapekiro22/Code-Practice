#include "BinaryTree.h"

// 递归实现先序遍历
status PreOrderTraverse(BiTree T, void (*visit)(BiTree))
{
    if(T != NULL)
    {
        visit(T);                              // 访问根节点
        PreOrderTraverse(T->lchild, visit);    // 先序遍历左子树
        PreOrderTraverse(T->rchild, visit);    // 先序遍历右子树
    }
    return OK;
}

status InOrderTraverse(BiTree T, void (*visit)(BiTree))
{
    if(T != NULL)
    {
        InOrderTraverse(T->lchild, visit);     // 中序遍历左子树
        visit(T);                              // 访问根节点
        InOrderTraverse(T->rchild, visit);     // 中序遍历右子树
    }
    return OK;
}

status PostOrderTraverse(BiTree T, void (*visit)(BiTree))
{
    if(T != NULL)
    {
        PostOrderTraverse(T->lchild, visit);   // 后序遍历左子树
        PostOrderTraverse(T->rchild, visit);   // 后序遍历右子树
        visit(T);                              // 访问根节点
    }
    return OK;
}

status LevelOrderTraverse(BiTree T, void (*visit)(BiTree))
{
    if(T == NULL) return OK; // 空树直接返回
    
    // 使用数组实现简单队列
    BiTree queue[128]; // 假设MAX_TREE_SIZE是预定义的足够大小
    int front = 0;              // 队列头指针
    int rear = 0;               // 队列尾指针
    
    // 根节点入队
    queue[rear++] = T;
    
    // 当队列不为空时循环处理
    while(front < rear)
    {
        // 出队一个节点并访问
        BiTree node = queue[front++];
        visit(node);
        
        // 左子节点存在则入队
        if(node->lchild != NULL)
            queue[rear++] = node->lchild;
        
        // 右子节点存在则入队
        if(node->rchild != NULL)
            queue[rear++] = node->rchild;
    }
    
    return OK;
}