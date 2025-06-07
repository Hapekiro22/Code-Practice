status InitGraphGroup(GraphGroup &Ggroup)
// 初始化图组
{
    Ggroup.Gnum = 0;
    for(int i = 0; i < MAX_VERTEX_NUM; i++) {
        Ggroup.name[i][0] = '\0'; // 初始化名称为空字符串
        Ggroup.Ggroup[i].vexnum = 0; // 初始化图为空
    }
    return OK;
}

status AddGraph(GraphGroup &Ggroup, char name[])
{
    if (Ggroup.Gnum >= MAX_VERTEX_NUM) {
        return ERROR; // 图组已满
    }
    
    strcpy(Ggroup.name[Ggroup.Gnum], name);
    Ggroup.Gnum++;
    
    return OK;
}

status RemoveGraph(GraphGroup &Ggroup, char name[])
{
    for(int i = 0; i < Ggroup.Gnum; i++) {
        if (strcmp(Ggroup.name[i], name) == 0) {
            // 找到图，删除
            for (int j = i; j < Ggroup.Gnum - 1; j++) {
                strcpy(Ggroup.name[j], Ggroup.name[j + 1]);
                Ggroup.Ggroup[j] = Ggroup.Ggroup[j + 1];
            }
            Ggroup.Gnum--;
            return OK;
        }
    }

    return ERROR; // 未找到图
}

int LocateGraph(GraphGroup Ggroup, char name[])
{
    for (int i = 0; i < Ggroup.Gnum; i++) {
        if (strcmp(Ggroup.name[i], name) == 0) {
            return i; // 找到图的索引
        }
    }
    
    return -1; // 未找到
}

status PrintGraphGroup(GraphGroup Ggroup)
{
    for (int i = 0; i < Ggroup.Gnum; i++) {
        printf("Graph %d: %s\n", i, Ggroup.name[i]);
        // 可以添加更多的打印信息，例如顶点和边的信息
    }
    
    return OK;
}

