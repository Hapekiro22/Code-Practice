#include "def.h"

//采用首插法创建邻接表
status CreateGraph(ALGraph &G, VertexType V[], KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i, j;
    ArcNode *p;
    
    // 检查顶点关键字是否有重复
    for (i = 0; V[i].key != -1; i++) {
        for (j = i + 1; V[j].key != -1; j++) {
            if (V[i].key == V[j].key) {
                return ERROR; // 存在重复关键字，返回ERROR
            }
        }
    }
    
    // 初始化图的基本信息
    G.vexnum = i;  // 顶点数量
    G.arcnum = 0;  // 初始化弧的数量为0
    
    // 初始化所有顶点的邻接表头节点
    for (i = 0; i < G.vexnum; i++) {
        G.vertices[i].data = V[i];     // 存储顶点信息
        G.vertices[i].firstarc = NULL; // 初始化为空链表
    }
    
    // 根据VR添加边（弧）
    for (i = 0; VR[i][0] != -1; i++) {
        int v1 = -1, v2 = -1;
        
        // 查找顶点的位置
        for (j = 0; j < G.vexnum; j++) {
            if (G.vertices[j].data.key == VR[i][0]) {
                v1 = j;
            }
            if (G.vertices[j].data.key == VR[i][1]) {
                v2 = j;
            }
        }
        
        // 如果找不到对应顶点，返回ERROR
        if (v1 == -1 || v2 == -1) {
            return ERROR;
        }
        
        // 创建新的弧节点，采用首插法添加到邻接表
        p = (ArcNode *)malloc(sizeof(ArcNode));
        if (!p) return OVERFLOW;
        
        p->adjvex = v2;
        p->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = p;
        G.arcnum++;
        
        // 如果是无向图，需要添加反向的弧
        if (G.kind == UDG || G.kind == UDN) {
            p = (ArcNode *)malloc(sizeof(ArcNode));
            if (!p) return OVERFLOW;
            
            p->adjvex = v1;
            p->nextarc = G.vertices[v2].firstarc;
            G.vertices[v2].firstarc = p;
        }
    }
    
    return OK;
    /********** End **********/
}