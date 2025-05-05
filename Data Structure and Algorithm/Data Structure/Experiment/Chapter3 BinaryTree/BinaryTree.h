#include "def.h"

// 全局变量，用于跟踪前序遍历序列的当前位置
int count = 0;

// 辅助函数：检查二叉树中是否存在相同关键字，但排除当前节点自身
status HasSameKey(BiTree T, KeyType key, BiTree currentNode) {
    if (T == NULL) return FALSE;
    
    // 检查当前节点的key是否匹配，但排除自身的比较
    if (T != currentNode && T->data.key == key) return TRUE;
    
    // 递归检查左右子树
    if (HasSameKey(T->lchild, key, currentNode)) return TRUE;
    if (HasSameKey(T->rchild, key, currentNode)) return TRUE;
    
    return FALSE;
}

status CreateBiTree(BiTree &T, TElemType definition[]) 
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 处理空节点标记（假设definition中的key为0表示空节点）
    if (definition[count].key == 0) {
        T = NULL;
        count++;
        return OK;
    }
    
    // 创建临时树根指针，用于检查重复key
    static BiTree root = NULL;
    
    // 第一个节点时初始化根指针
    if (count == 0) {
        root = NULL;
    }
    
    // 分配新节点
    T = (BiTNode *)malloc(sizeof(BiTNode));
    if (!T) return ERROR; // 内存分配失败
    
    // 设置节点数据
    T->data = definition[count];
    
    // 检查树中是否已存在相同关键字
    // 第一个节点时，root为空，设置root
    if (root == NULL) {
        root = T;
    } 
    else if (HasSameKey(root, T->data.key, T)) {  // 传入当前节点T以便排除自身
        free(T); // 释放已分配的内存
        T = NULL;
        return ERROR; // 存在相同关键字，返回错误
    }
    
    // 递增count，准备读取下一个节点
    count++;
    
    // 递归构建左子树
    status leftStatus = CreateBiTree(T->lchild, definition);
    if (leftStatus == ERROR) return ERROR;
    
    // 递归构建右子树
    status rightStatus = CreateBiTree(T->rchild, definition);
    if (rightStatus == ERROR) return ERROR;
    
    return OK;
}

status ClearBiTree(BiTree *T)
//将二叉树设置成空，并删除所有结点，释放结点空间
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(*T == NULL)
        return OK;

    status error_l = ClearBiTree(&((*T) -> lchild));
    if(error_l == ERROR) return ERROR;
    status error_r = ClearBiTree(&((*T)->rchild));
    if(error_r == ERROR) return ERROR;

    free(*T);
    *T = NULL;

    return OK;
    /********** End **********/
}

int BiTreeDepth(BiTree T)
//求二叉树T的深度
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // 空树深度为0
    if(T == NULL)
        return 0;
    
    // 分别计算左右子树的深度
    int depth_l = BiTreeDepth(T->lchild);
    int depth_r = BiTreeDepth(T->rchild);
    
    // 当前树的深度为较深子树的深度加1
    return 1 + (depth_l > depth_r ? depth_l : depth_r);
    /********** End **********/
}


BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T == NULL)
        return NULL;
    
    BiTNode* loc_node = NULL;

    if((T->data).key == e)
        return T;
    else
    {
        if(loc_node = LocateNode(T -> lchild,e))
            return loc_node;
        if(loc_node = LocateNode(T -> rchild,e))
            return loc_node;
    }

    return loc_node;

    /********** End **********/
}

status Assign(BiTree &T, KeyType e, TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL) return ERROR;
    
    if (e != value.key) {
        if (HasSameKey(T, value.key, NULL)) {
            return ERROR;
        }
    }
    
    BiTNode *node = LocateNode(T, e);
    
    if (node == NULL) return ERROR;
    
    node->data = value;
    
    return OK;
    /********** End **********/
}


BiTNode* GetSibling(BiTree T, KeyType e)
//实现获得兄弟结点
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (T == NULL || (T->lchild == NULL && T->rchild == NULL))
        return NULL;
    
    if (T->lchild != NULL && T->lchild->data.key == e)
        return T->rchild;  
    
    if (T->rchild != NULL && T->rchild->data.key == e)
        return T->lchild;  
    
    BiTNode* sibling = NULL;
    if (T->lchild != NULL)
        sibling = GetSibling(T->lchild, e);
    
    if (sibling != NULL)
        return sibling;
    
    if (T->rchild != NULL)
        sibling = GetSibling(T->rchild, e);
    
    return sibling;
    /********** End **********/
}