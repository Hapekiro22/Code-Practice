
// 全局变量，用于跟踪前序遍历序列的当前位置
int count_def = 0;

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

status CreateBiTree_Pre(BiTree *T, TElemType definition[]) 
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    if(*T != NULL) return INFEASIBLE; // 如果树已经存在，返回错误

    // 处理空节点标记（假设definition中的key为0表示空节点）
    if (definition[count_def].key == 0) {
        *T = NULL;
        count_def++;
        return OK;
    }
    
    // 创建临时树根指针，用于检查重复key
    static BiTree root = NULL;
    
    // 第一个节点时初始化根指针
    if (count_def == 0) {
        root = NULL;
    }
    
    // 分配新节点
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    if (!(*T)) return ERROR; // 内存分配失败

    (*T) -> lchild = NULL; // 初始化左子树
    (*T) -> rchild = NULL; // 初始化右子树
    
    // 设置节点数据
    (*T)->data = definition[count_def];
    
    // 检查树中是否已存在相同关键字
    // 第一个节点时，root为空，设置root
    if (root == NULL) {
        root = *T;
    } 
    else if (HasSameKey(root, (*T)->data.key, *T)) {  // 传入当前节点T以便排除自身
        free(*T); // 释放已分配的内存
        *T = NULL;
        return ERROR; // 存在相同关键字，返回错误
    }
    
    // 递增count，准备读取下一个节点
    count_def++;
    
    // 递归构建左子树
    status leftStatus = CreateBiTree_Pre(&((*T)->lchild), definition);
    if (leftStatus == ERROR) return ERROR;
    
    // 递归构建右子树
    status rightStatus = CreateBiTree_Pre(&((*T)->rchild), definition);
    if (rightStatus == ERROR) return ERROR;
    
    return OK;
}

typedef struct {
    int pos;
    TElemType data;
} DEF;

status CreateBiTree(BiTree *T,DEF definition[])
{
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
       p[j]=(BiTNode *)malloc(sizeof(BiTNode));
       p[j]->data=definition[i].data;
       p[j]->lchild=NULL;
       p[j]->rchild=NULL;
       if (j!=1)
       		if (j%2)   p[j/2]->rchild=p[j];  
       	   else      p[j/2]->lchild=p[j];
       i++;
    }
    *T=p[1];
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


bool BiTreeEmpty(BiTree T)
//判断二叉树是否为空
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(T == NULL)
        return true;
    else
        return false;
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

BiTNode* GetParent(BiTree T, KeyType e)
//查找关键字为e的节点的父节点
{
    // 空树或根节点没有父节点
    if(T == NULL) 
        return NULL;
    
    // 检查当前节点的左子节点
    if(T->lchild != NULL && T->lchild->data.key == e)
        return T;  // 找到了，返回父节点
    
    // 检查当前节点的右子节点
    if(T->rchild != NULL && T->rchild->data.key == e)
        return T;  // 找到了，返回父节点
    
    // 在左子树中递归查找
    BiTNode* parent = NULL;
    if(T->lchild != NULL) {
        parent = GetParent(T->lchild, e);
        if(parent != NULL)
            return parent;  // 在左子树中找到了父节点
    }
    
    // 在右子树中递归查找
    if(T->rchild != NULL) {
        parent = GetParent(T->rchild, e);
        if(parent != NULL)
            return parent;  // 在右子树中找到了父节点
    }
    
    // 如果左右子树都没找到，返回NULL
    return NULL;
}

status Assign(BiTree *T, KeyType e, TElemType value)
//实现结点赋值。此题允许通过增加其它函数辅助实现本关任务
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (*T == NULL) return ERROR;
    
    if (e != value.key) {
        if (HasSameKey(*T, value.key, NULL)) {
            return ERROR;
        }
    }
    
    BiTNode *node = LocateNode(*T, e);
    
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

status InsertNode(BiTree *T, KeyType e, int LR, TElemType c)
{
    // 特殊情况：插入作为根节点
    if(LR == -1)
    {
        BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
        if(newNode == NULL) return ERROR;
        newNode->data = c;
        newNode->lchild = NULL;
        newNode->rchild = *T;  // 原树作为右子树
        *T = newNode;
        return OK;
    }

    if(HasSameKey(*T, c.key, NULL)) return ERROR;

    BiTNode *basicNode = LocateNode(*T, e);
    if(basicNode == NULL) return ERROR;
    
    BiTNode* newNode = (BiTNode*)malloc(sizeof(BiTNode));
    if(newNode == NULL) return ERROR;
    newNode->data = c;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    // 插入到左子树
    if(LR == 0)
    {
        // 若原左子树存在，则保存它
        BiTNode* originalLeft = basicNode->lchild;
        
        basicNode->lchild = newNode;
        
        if(originalLeft != NULL) {
            newNode->rchild = originalLeft;
        }
    }
    // 插入到右子树
    else if(LR == 1)
    {
        // 若原右子树存在，则保存它
        BiTNode* originalRight = basicNode->rchild;
        
        basicNode->rchild = newNode;
        
        if(originalRight != NULL) {
            newNode->rchild = originalRight;
        }
    }
    else
        return ERROR; // 无效的LR值

    return OK;
}

status DeleteNode(BiTree *T, KeyType e)
{
    BiTNode *nodeToDelete = LocateNode(*T, e);
    if(nodeToDelete == NULL) return ERROR;

    BiTNode *parent = GetParent(*T, e);
    if(parent == NULL) return ERROR; // 根节点没有父节点，无法删除

    status position = 0; // 0表示左子树，1表示右子树
    if(parent->rchild == nodeToDelete) position = 1;

    BiTNode *lchild = nodeToDelete->lchild;
    BiTNode *rchild = nodeToDelete->rchild;

    if(lchild != NULL && rchild != NULL)
    {
        BiTNode *LC_most_right = lchild;
        while(LC_most_right->rchild != NULL)
            LC_most_right = LC_most_right->rchild;
        LC_most_right->rchild = rchild;     // 将右子树连接到左子树的最右节点

        if(position == 0)
            parent->lchild = lchild; // 将左子树连接到父节点
        else
            parent->rchild = lchild; // 将左子树连接到父节点
    }
    else if(lchild != NULL && rchild == NULL)
    {
        if(position == 0)
            parent->lchild = lchild; // 将左子树连接到父节点
        else
            parent->rchild = lchild; // 将左子树连接到父节点
    }
    else if(lchild == NULL && rchild != NULL)
    {
        if(position == 0)
            parent->lchild = rchild; // 将右子树连接到父节点
        else
            parent->rchild = rchild; // 将右子树连接到父节点
    }
    else
    {
        if(position == 0)
            parent->lchild = NULL; // 删除左子树
        else
            parent->rchild = NULL; // 删除右子树
    }

    free(nodeToDelete);
    nodeToDelete = NULL; 

    return OK;
}


status DeleteNode_HeadA(BiTree &T, KeyType e)
{
    BiTNode *nodeToDelete = LocateNode(T, e);
    if(nodeToDelete == NULL) return ERROR;

    BiTNode *parent = GetParent(T, e);
    // 处理根节点的特殊情况
    if(parent == NULL) {
        // 确认是根节点
        if(nodeToDelete != T) return ERROR;
        
        BiTNode *lchild = nodeToDelete->lchild;
        BiTNode *rchild = nodeToDelete->rchild;
        
        // 情况1：根节点有两个子节点
        if(lchild != NULL && rchild != NULL) {
            // 找到左子树的最右节点
            BiTNode *LC_most_right = lchild;
            while(LC_most_right->rchild != NULL)
                LC_most_right = LC_most_right->rchild;
            
            // 将右子树接到左子树最右节点的右子树
            LC_most_right->rchild = rchild;
            
            // 用左子树替换根节点
            T = lchild;
        }
        // 情况2：根节点只有左子树
        else if(lchild != NULL) {
            T = lchild;
        }
        // 情况3：根节点只有右子树
        else if(rchild != NULL) {
            T = rchild;
        }
        // 情况4：根节点是叶子节点
        else {
            T = NULL;
        }

        free(nodeToDelete);
        return OK;
    }

    status position = 0; // 0表示左子树，1表示右子树
    if(parent->rchild == nodeToDelete) position = 1;

    BiTNode *lchild = nodeToDelete->lchild;
    BiTNode *rchild = nodeToDelete->rchild;

    if(lchild != NULL && rchild != NULL)
    {
        BiTNode *LC_most_right = lchild;
        while(LC_most_right->rchild != NULL)
            LC_most_right = LC_most_right->rchild;
        LC_most_right->rchild = rchild;     // 将右子树连接到左子树的最右节点

        if(position == 0)
            parent->lchild = lchild; // 将左子树连接到父节点
        else
            parent->rchild = lchild; // 将左子树连接到父节点
        
    }

    else if(lchild != NULL && rchild == NULL)
    {
        if(position == 0)
            parent->lchild = lchild; // 将左子树连接到父节点
        else
            parent->rchild = lchild; // 将左子树连接到父节点
    }
    else if(lchild == NULL && rchild != NULL)
    {
        if(position == 0)
            parent->lchild = rchild; // 将右子树连接到父节点
        else
            parent->rchild = rchild; // 将右子树连接到父节点
    }
    else
    {
        if(position == 0)
            parent->lchild = NULL; // 删除左子树
        else
            parent->rchild = NULL; // 删除右子树
    }

    free(nodeToDelete);
    nodeToDelete = NULL; 

    return OK;

}