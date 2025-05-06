#include "BinaryTree.h"

//获取T的最大根节点到叶节点的key值和（一条路径）
int MaxPath(BiTree T, int *maxPath)
{
    if (T == NULL) return 0; // 空树返回0

    int leftMax = MaxPath(T->lchild, maxPath); // 左子树的最大路径和
    int rightMax = MaxPath(T->rchild, maxPath); // 右子树的最大路径和

    // 更新当前节点的路径和
    int currentMax = T->data.key + (leftMax > rightMax ? leftMax : rightMax);

    // 更新全局最大路径和
    if (currentMax > *maxPath) {
        *maxPath = currentMax;
    }

    return currentMax;
}

BiTNode* LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2)
{
    if (T == NULL) return NULL; // 空树返回NULL

    // 如果当前节点是e1或e2，则返回当前节点
    if (T->data.key == e1 || T->data.key == e2) {
        return T;
    }

    // 递归查找左子树和右子树
    BiTNode* left = LowestCommonAncestor(T->lchild, e1, e2);
    BiTNode* right = LowestCommonAncestor(T->rchild, e1, e2);

    // 如果在左右子树中都找到了，则当前节点是最近公共祖先
    if (left != NULL && right != NULL) {
        return T;
    }

    // 否则，返回非NULL的子节点（如果有的话）
    return left != NULL ? left : right;
}

status InvertTree(BiTree *T)
{
    if (*T == NULL) return OK; // 空树直接返回

    // 交换左右子树
    BiTree temp = (*T)->lchild;
    (*T)->lchild = (*T)->rchild;
    (*T)->rchild = temp;

    // 递归反转左右子树
    InvertTree(&(*T)->lchild);
    InvertTree(&(*T)->rchild);

    return OK;
}

