
int GetLocation(ALGraph &G, KeyType key)
{
    int i;

    for(i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == key)
            return i;
    }

    return -1;
}

status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i,j;
    ArcNode *p1, *p2;

    for(i = 0; V[i].key != -1; i++);

    G.vexnum = i;
    G.arcnum = 0;

    for(i = 0; i < G.vexnum; i++)
    {
        G.vertices[i].data = V[i];
        G.vertices[i].firstarc = NULL;
    }

    if(i < G.vexnum || i == 0)
        return ERROR;

    for(i = 0; i < G.vexnum; i++)
    {
        for(j = i + 1; j < G.vexnum; j++)
        {
            if(V[i].key == V[j].key)
                return ERROR;
        }
    }

    for(j = 0; VR[j][0] != -1; j++)
    {
        int loc1,loc2;
        loc1 = GetLocation(G,VR[j][0]);
        loc2 = GetLocation(G,VR[j][1]);

        if(loc1 == -1 || loc2 == -1)
            return ERROR;
    
        p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1 -> adjvex = loc2;
        p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2 -> adjvex = loc1;

        ArcNode *temp = G.vertices[loc1].firstarc;
        G.vertices[loc1].firstarc = p1;
        p1 -> nextarc = temp;
        temp = G.vertices[loc2].firstarc;
        G.vertices[loc2].firstarc = p2;
        p2 -> nextarc = temp;
        G.arcnum++;
        
    }

    G.kind = UDN;
    return OK;

    /********** End **********/
}

status DestroyGraph(ALGraph &G)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i;
    ArcNode *p1, *p2;

    for(i = 0; i < G.vexnum; i++)
    {
        p1 = G.vertices[i].firstarc;
        while(p1 != NULL)
        {
            p2 = p1;
            p1 = p1 -> nextarc;
            free(p2);
        }
    }

    G.vexnum = 0;
    G.arcnum = 0;

    return OK;

    /********** End **********/
}

status PutVex(ALGraph &G,KeyType u,VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = GetLocation(G, u);
    if(i == -1) return ERROR;

    for(int j = 0; j < G.vexnum; j++)
    {
        if(G.vertices[j].data.key == value.key && i != j)
            return ERROR;
    }

    G.vertices[i].data = value;
    return OK;

    /********** End **********/
}

int FirstAdjVex(ALGraph G,KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = GetLocation(G, u);
    if(i == -1) return -1;

    ArcNode *p = G.vertices[i].firstarc;
    if(p == NULL) return -1;

    return p -> adjvex;

    /********** End **********/
}

int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = GetLocation(G, v);
    int j = GetLocation(G, w);
    if(i == -1) return -1;

    ArcNode *p = G.vertices[i].firstarc;
    while(p != NULL)
    {
        if(p -> adjvex == j)
            break;
        p = p -> nextarc;
    }

    if(p == NULL || p -> nextarc == NULL) return -1;
  
    return p -> nextarc -> adjvex;

    /********** End **********/
}

status InsertVex(ALGraph &G,VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(G.vexnum >= MAX_VERTEX_NUM) return ERROR;

    for(int i = 0; i < G.vexnum; i++)
    {
        if(G.vertices[i].data.key == v.key)
            return ERROR;
    }

    G.vertices[G.vexnum].data = v;
    G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++;

    return OK;

    /********** End **********/
}

status DeleteVex(ALGraph &G, KeyType u)
{
    int i = GetLocation(G, u);
    if(i == -1) return ERROR;

    // 计数待删除的边数
    int edgeCount = 0;
    
    // 释放顶点的出边
    ArcNode *p = G.vertices[i].firstarc;
    while(p != NULL)
    {
        ArcNode *temp = p;
        p = p->nextarc;
        free(temp);
        edgeCount++;  // 每释放一条边，计数加1
    }

    // 处理其他顶点的入边和对应的出边
    for(int j = 0; j < G.vexnum; j++)
    {
        if(j == i) continue;  // 跳过被删除的顶点
        
        ArcNode *p1 = G.vertices[j].firstarc;
        ArcNode *p2 = NULL; 

        while(p1 != NULL)
        {
            if(p1->adjvex == i)  // 找到指向要删除顶点的边
            {
                // 删除这条边
                if(p2 == NULL)  // 如果是第一条边
                {
                    G.vertices[j].firstarc = p1->nextarc;
                    free(p1);
                    p1 = G.vertices[j].firstarc;
                }
                else  // 如果不是第一条边
                {
                    p2->nextarc = p1->nextarc;
                    free(p1);
                    p1 = p2->nextarc;
                }
                edgeCount++;  // 每删除一条边，计数加1
            }
            else
            {
                // 调整大于i的adjvex值
                if(p1->adjvex > i) 
                    p1->adjvex--;
                
                p2 = p1;
                p1 = p1->nextarc;
            }
        }
    }

    // 移动顶点数组
    for(int j = i; j < G.vexnum - 1; j++)
    {
        G.vertices[j] = G.vertices[j + 1];
    }

    // 更新顶点数和边数
    G.vexnum--;
    G.arcnum -= edgeCount / 2;  // 因为是无向图，每条边计算了两次

    if(G.vexnum == 0) return ERROR;

   // printf("Finished\n");

    return OK;
}

status InsertArc(ALGraph &G,KeyType u,KeyType v)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int loc1 = GetLocation(G, u);
    int loc2 = GetLocation(G, v);
    if(loc1 == -1 || loc2 == -1) return ERROR;

    //check if the edge already exists
    ArcNode *p = G.vertices[loc1].firstarc;
    while(p != NULL)
    {
        if(p->adjvex == loc2) return ERROR;
        p = p->nextarc;
    }

    ArcNode *p1 = (ArcNode *)malloc(sizeof(ArcNode));
    p1 -> adjvex = loc2;
    p1 -> nextarc = G.vertices[loc1].firstarc;
    G.vertices[loc1].firstarc = p1;

    ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
    p2 -> adjvex = loc1;
    p2 -> nextarc = G.vertices[loc2].firstarc;
    G.vertices[loc2].firstarc = p2;

    G.arcnum++;

    return OK;

    /********** End **********/
}

status DeleteArc(ALGraph &G,KeyType v,KeyType w)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int loc1 = GetLocation(G, v);
    int loc2 = GetLocation(G, w);
    if(loc1 == -1 || loc2 == -1) return ERROR;

    int flag = 0;

    ArcNode *p = G.vertices[loc1].firstarc;
    ArcNode *p2 = NULL;

    while(p != NULL)
    {
        if(p->adjvex == loc2)
        {
            if(p2 == NULL)  // 如果是第一条边
            {
                G.vertices[loc1].firstarc = p->nextarc;
                free(p);
                p = G.vertices[loc1].firstarc;
            }
            else  // 如果不是第一条边
            {
                p2->nextarc = p->nextarc;
                free(p);
                p = p2->nextarc;
            }

            flag = 1;

        }
        else
        {
            p2 = p;
            p = p->nextarc;
        }
    }

    if(!flag) return ERROR;

    // 删除第二个顶点的出边
    p = G.vertices[loc2].firstarc;
    p2 = NULL;

    while(p != NULL)
    {
        if(p->adjvex == loc1)
        {
            if(p2 == NULL)  // 如果是第一条边
            {
                G.vertices[loc2].firstarc = p->nextarc;
                free(p);
                p = G.vertices[loc2].firstarc;
            }
            else  // 如果不是第一条边
            {
                p2->nextarc = p->nextarc;
                free(p);
                p = p2->nextarc;
            }
        }
        else
        {
            p2 = p;
            p = p->nextarc;
        }
    }

    G.arcnum--;

    return OK;

    /********** End **********/
}

// 辅助函数：递归进行深度优先搜索
void DFS(ALGraph &G, int v, int visited[], void (*visit)(VertexType)) {
    // 访问当前顶点
    if(visit != NULL)
        visit(G.vertices[v].data);
    visited[v] = true;
    
    // 遍历当前顶点的所有邻接顶点
    ArcNode *p = G.vertices[v].firstarc;
    while (p != NULL) {
        // 如果邻接顶点未被访问，则递归访问它
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex, visited, visit);
        }
        p = p->nextarc;
    }
}

status DFSTraverse(ALGraph &G, void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (G.vexnum == 0) return ERROR; // 如果图为空，返回错误
    
    // 初始化访问标记数组
    int visited[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    // 从每个未访问的顶点开始进行深度优先搜索
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            DFS(G, i, visited, visit);
        }
    }
    
    return OK;
    /********** End **********/
}

status BFSTraverse(ALGraph &G, void (*visit)(VertexType))
//对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (G.vexnum == 0) return ERROR; // 如果图为空，返回错误
    
    // 初始化访问标记数组
    bool visited[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; i++) {
        visited[i] = false;
    }
    
    // 创建队列用于BFS
    int queue[MAX_VERTEX_NUM];
    int front = 0;
    int rear = 0;
    
    // 从每个未访问的顶点开始进行广度优先搜索
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            // 访问当前顶点
            visit(G.vertices[i].data);
            visited[i] = true;
            
            // 将当前顶点入队
            queue[rear++] = i;
            
            // 队列非空时循环处理
            while (front < rear) {
                // 出队一个顶点
                int v = queue[front++];
                
                // 访问该顶点的所有未访问邻接点
                ArcNode *p = G.vertices[v].firstarc;
                while (p != NULL) {
                    int w = p->adjvex;
                    if (!visited[w]) {
                        visit(G.vertices[w].data);
                        visited[w] = true;
                        queue[rear++] = w; // 新发现的顶点入队
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    
    return OK;
    /********** End **********/
}

void PrintVertex(VertexType v)
{
    printf("Key: %d, Others: %s\n", v.key, v.others);
}

