status BFSTraverse(ALGraph &G, void (*visit)(VertexType));
void DFS(ALGraph &G, int v, bool visited[], void (*visit)(VertexType));

//Get All vertices whose distance from the certain vertex is less than k
VertexType *VerticesSetLessThanK(ALGraph G, KeyType v, int k)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i;
    int visited[MAX_VERTEX_NUM] = {0};
    int distance[MAX_VERTEX_NUM];
    VertexType *result = (VertexType *)malloc(G.vexnum * sizeof(VertexType));
    int count = 0;

    for(int i = 0; i < G.vexnum; i++)
    {
        result[i].key = -1; // 初始化结果数组
    }
    
    // 初始化访问标记和距离数组
    for (i = 0; i < G.vexnum; i++) {
        visited[i] = 0;
        distance[i] = -1;
    }
    
    // 查找起始顶点的位置
    int startIndex = GetLocation(G, v);
    if (startIndex == -1) {
        free(result);
        return NULL; // 起始顶点不存在
    }
    
    // 创建队列用于BFS
    int queue[MAX_VERTEX_NUM];
    int front = 0, rear = 0;
    
    // 将起始顶点入队
    queue[rear++] = startIndex;
    visited[startIndex] = 1;
    distance[startIndex] = 0;
    result[count++] = G.vertices[startIndex].data;
    
    // BFS遍历
    while (front < rear) {
        // 出队一个顶点
        int current = queue[front++];
        
        // 如果当前顶点的距离已经等于k-1，那么它的邻接点距离将是k，不需要继续遍历
        if (distance[current] == k - 1) {
            continue;
        }
        
        // 访问所有邻接点
        ArcNode *p = G.vertices[current].firstarc;
        while (p != NULL) {
            int adjIndex = p->adjvex;
            if (!visited[adjIndex]) {
                visited[adjIndex] = 1;
                distance[adjIndex] = distance[current] + 1;
                
                // 添加到结果集
                result[count++] = G.vertices[adjIndex].data;
                
                // 只有当距离小于k-1的顶点才入队，以便继续遍历其邻接点
                if (distance[adjIndex] < k - 1) {
                    queue[rear++] = adjIndex;
                }
            }
            p = p->nextarc;
        }
    }
    
    // 返回结果数组的一个副本，只包含需要的部分
    VertexType *finalResult = (VertexType *)malloc((count + 1) * sizeof(VertexType));
    for (i = 0; i < count; i++) {
        finalResult[i] = result[i];
    }
    finalResult[count].key = -1; // 设置结束标记
    free(result);
    
    return finalResult;
    /********** End *********/
}

//Dijikstra algorithm
int ShortestPath(ALGraph G, KeyType u, KeyType v)
{
    int i, j, min, minIndex;
    int visited[MAX_VERTEX_NUM] = {0};
    int dist[MAX_VERTEX_NUM];

    int startIndex = GetLocation(G, u);
    int endIndex  = GetLocation(G, v);
    if(startIndex == -1 || endIndex == -1) return -1; // 起始或结束顶点不存在

    if(startIndex == endIndex) return 0; // 起始和结束顶点相同

    for(i = 0; i < G.vexnum; i++)
    {
        dist[i] = 32767;
    }

    dist[startIndex] = 0; // 起始顶点到自身的距离为0

    for(i = 0; i < G.vexnum; i++)
    {
        min = 32767;
        minIndex = -1;

        for(j = 0; j < G.vexnum; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                minIndex = j;
            }
        }

        if(minIndex == -1) break; // 所有可达顶点都已访问

        visited[minIndex] = 1; // 标记当前顶点为已访问

        if(minIndex == endIndex) return dist[minIndex]; // 找到目标顶点

        ArcNode *p = G.vertices[minIndex].firstarc;
        while(p != NULL)
        {
            int adjIndex = p -> adjvex;

            int weight = 1;

            if(!visited[adjIndex] && dist[minIndex] != 32767 &&
                dist[minIndex] + weight < dist[adjIndex])
            {
                dist[adjIndex] = dist[minIndex] + weight;
            }

            p = p -> nextarc;
        }

    }

    if(dist[endIndex] == 32767) 
    {
        return -1; // 目标顶点不可达
    }

    return dist[endIndex]; // 返回最短路径长度
}

int ConnectedComponentsNum(ALGraph G)
{
    int i, j, count = 0;
    int visited[MAX_VERTEX_NUM] = {0};

    for(i = 0; i < G.vexnum; i++)
    {
        if(!visited[i])
        {
            count++;
            // 深度优先搜索遍历当前连通分量
            DFS(G, i, visited, NULL);
        }
    }

    return count;
}

void PrintGraphList(ALGraph G)
{
    int i;
    ArcNode *p;

    for(i = 0; i < G.vexnum; i++)
    {
        printf("Vertex %d (%s): ", G.vertices[i].data.key, G.vertices[i].data.others);
        p = G.vertices[i].firstarc;
        while(p != NULL)
        {
            printf("%d ", G.vertices[p->adjvex].data.key);
            p = p->nextarc;
        }
        printf("\n");
    }
}




