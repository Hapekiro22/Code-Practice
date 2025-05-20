
// 递归实现先序遍历
status PreOrderTraverse(BiTree T, void (*visit)(BiTree))
{
    if(T != NULL)
    {
        visit(T);                              // 访问根节点
        PreOrderTraverse(T->lchild, visit);    // 先序遍历左子树
        PreOrderTraverse(T->rchild, visit);    // 先序遍历右子树
    }
    else    
        visit(NULL);                        // 访问空节点
        
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
    else
        visit(NULL);                        // 访问空节点
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
    else
        visit(NULL);                        // 访问空节点
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

status PreOrderTraverse_Stack(BiTree T, void (*visit)(BiTree))
{
    if(T == NULL) return OK; // 空树直接返回
    
    BiTree stack[128]; // 假设MAX_TREE_SIZE是预定义的足够大小
    int top = -1; // 栈顶指针
    
    // 根节点入栈
    stack[++top] = T;
    
    while(top >= 0)
    {
        // 出栈一个节点并访问
        BiTree node = stack[top--];
        visit(node);
        
        // 右子节点先入栈，左子节点后入栈
        if(node->rchild != NULL)
            stack[++top] = node->rchild;
        if(node->lchild != NULL)
            stack[++top] = node->lchild;
    }
    
    return OK;
}

void ShowNode(BiTree T)
{
    if(T != NULL)
        printf("%d,%s ", T->data.key, T->data.others); // 显示节点信息
    else;

    return;
       // printf("null "); // 显示空节点
}