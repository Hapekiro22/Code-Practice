status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE *fp;
    int i, j, edgeCount = 0;
    ArcNode *p;
    
    // 创建边的数组用于排序
    typedef struct {
        KeyType v1;
        KeyType v2;
    } Edge;
    
    Edge edges[MAX_ARC_NUM];
    
    // 打开文件，如果失败则返回ERROR
    if ((fp = fopen(FileName, "w")) == NULL) {
        return ERROR;
    }
    
    // 写入图的基本信息：类型、顶点数和边数
    fprintf(fp, "%d %d %d\n", G.kind, G.vexnum, G.arcnum);
    
    // 写入所有顶点的信息（按照数组顺序）
    for (i = 0; i < G.vexnum; i++) {
        fprintf(fp, "%d %s\n", G.vertices[i].data.key, G.vertices[i].data.others);
    }
    
    // 收集所有边的信息
    for (i = 0; i < G.vexnum; i++) {
        p = G.vertices[i].firstarc;
        while (p != NULL) {
            // 对于无向图，只收集一次边（只有当i<p->adjvex时）
            if (G.kind == DG || G.kind == DN || i < p->adjvex) {
                edges[edgeCount].v1 = G.vertices[i].data.key;
                edges[edgeCount].v2 = G.vertices[p->adjvex].data.key;
                edgeCount++;
            }
            p = p->nextarc;
        }
    }
    
    // 对边进行冒泡排序（先按v1排序，v1相同时按v2排序）
    for (i = 0; i < edgeCount - 1; i++) {
        for (j = 0; j < edgeCount - i - 1; j++) {
            if (edges[j].v1 > edges[j + 1].v1 || 
               (edges[j].v1 == edges[j + 1].v1 && edges[j].v2 > edges[j + 1].v2)) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    
    // 写入排序后的边信息
    for (i = 0; i < edgeCount; i++) {
        fprintf(fp, "%d %d\n", edges[i].v1, edges[i].v2);
    }
    
    fclose(fp);
    return OK;
    /********** End 1 **********/
}

status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    FILE *fp;
    int i, arcnum;
    KeyType v1, v2;
    VertexType vertices[MAX_VERTEX_NUM];
    KeyType VR[MAX_ARC_NUM][2];
    char others[20];
    
    // 打开文件，如果失败则返回ERROR
    if ((fp = fopen(FileName, "r")) == NULL) {
        return ERROR;
    }
    
    // 读取图的基本信息：类型、顶点数和边数
    if (fscanf(fp, "%d %d %d", &G.kind, &G.vexnum, &arcnum) != 3) {
        fclose(fp);
        return ERROR;
    }
    
    // 读取顶点信息
    for (i = 0; i < G.vexnum; i++) {
        if (fscanf(fp, "%d %s", &vertices[i].key, others) != 2) {
            fclose(fp);
            return ERROR;
        }
        strcpy(vertices[i].others, others);
    }
    
    // 设置结束标记
    vertices[i].key = -1;
    
    // 读取边信息
    i = 0;
    while (fscanf(fp, "%d %d", &v1, &v2) == 2 && i < MAX_ARC_NUM) {
        VR[i][0] = v1;
        VR[i][1] = v2;
        i++;
    }
    
    // 设置边列表的结束标记
    VR[i][0] = -1;
    VR[i][1] = -1;
    
    fclose(fp);
    
    // 使用CreateGraph函数创建图
    if (CreateCraph(G, vertices, VR) != OK) {
        return ERROR;
    }
    
    return OK;
    /********** End 2 **********/
}