#include "def.h"
#include "Graph.h"
#include "Graph-Multi.h"
#include "Graph-Addons.h"
#include "Graph-IO.h"

int main()
{
    int mode = 1, op = 1,count = 0,temp = 0; // 操作码
    ALGraph *G_operated = NULL;
    ALGraph G_single; // 单棵图指针
    GraphGroup Graphs;
    InitGraphGroup(Graphs); // 初始化多棵图

    VertexType V[30];
    KeyType VR[100][2];

    char fileName[30];
    char graphName[20];

    int graph_idx = 0;
    int i,j,k,flag = 1;
    int first,next;
    int loc = -1,loc1 = -1,loc_idx = -1,pathLength;

    KeyType key,key1,key2;
    VertexType v;
    VertexType *result;

    while(mode)
    {
        system("cls");    printf("\n\n");
        printf("          Menu for Mode Selection \n");
        printf("------------------------------------------------------\n");
        printf("    	  1. Single Graph \n");
        printf("    	  2. Multi Graphs \n");
        printf("    	  0. Exit \n");
        printf("------------------------------------------------------\n");
        printf("    Choose the mode from 0 to 2: ");
        scanf("%d",&mode);
        G_operated = NULL; // 重置操作的链表指针
       
        while(op)
        {

            if(mode == 2)
            {
                system("cls");    printf("\n\n");
                printf("------------------------------------------------------\n");
                printf("          Multi-BiTrees Operation Mode:\n");
                printf("------------------------------------------------------\n"); 
                if(graph_idx >= Graphs.Gnum)
                {
                    G_operated = NULL;
                    printf("                          No graph exists!\n");
                    printf("------------------------------------------------------\n");
                }
                else
                {
                    G_operated = &Graphs.Ggroup[graph_idx];
                    printf("                  Current list: %s", Graphs.name[graph_idx]);
                    printf("    List id: %d", graph_idx + 1);
                    if(Graphs.Ggroup[graph_idx].vexnum == 0)
                    printf("  (Empty)");
                    printf("\n------------------------------------------------------\n");
                }
            } 
            else if(mode == 1)
            {
                G_operated = &G_single;
                system("cls");    printf("\n\n");
                printf("---------------------------------------------------------\n");
                printf("          Single-Graph Operation Mode:\n");
                printf("---------------------------------------------------------\n"); 
            }
            else if(mode == 0)
            {
                printf("Exiting...\n");
                break;
            }
            else 
            {
                printf("Invalid mode!\n");
                continue;
            }

            printf("          Menu for Operation Selection \n");
            printf("---------------------------------------------------------\n");
            printf("    	  1. CreateGraph           7. InsertVex\n");
            printf("    	  2. DestroyGraph          8. DeleteVex\n");
            printf("    	  3. GetLocation           9. InsertArc\n");
            printf("    	  4. PutVex                10. DeleteArc\n");
            printf("    	  5. FirstAdjVex           11. DFSTraverse\n");
            printf("    	  6. NextAdjVex            12. BFSTraverse\n");
            printf("---------------------------------------------------------\n");
            printf("         File Operation Menu \n");
            printf("---------------------------------------------------------\n");
            printf("    	  13. SaveGraph            14. LoadGraph\n");
            printf("---------------------------------------------------------\n");
            printf("         Additional Functions Menu \n");
            printf("---------------------------------------------------------\n");
            printf("    	  15. VerticesSetLessThanK  17. ConnectedComponentsNum\n");
            printf("          16. ShortestPath          18. PrintGraphList\n");
            printf("---------------------------------------------------------\n");

            if(mode == 2)
            {
                printf("         Multi-BiTrees Operation Selection \n");
                printf("---------------------------------------------------------\n");
                printf("    	  19. AddGraph             22. PrintGraphGroup\n");
                printf("    	  20. RemoveGraph          23. SwitchGraph\n");
                printf("    	  21. LocateGraph          24. InitGraphGroup \n");
                printf("---------------------------------------------------------\n");
            }

            printf("         0.Exit\n");
            printf("--------------------------------------------------------\n\n");
            printf("    Choose your operations [0~%d]: ", mode == 2 ? 25 : 14);

            scanf("%d", &op);
            if(op == 0)
            {
                printf("Returning to Main Menu...\n");
                op = 1;
                break;
            }

            if(mode == 2 && op != 19 && op != 22 && op != 23 && Graphs.Gnum <= graph_idx)
            {
                printf("No graph exist! Please create a tree first.\n");
                op = 1; // 重置操作码
                getchar(); // 清除缓冲区中的换行符
                getchar(); // 等待用户输入
                continue;
            }

            switch(op)
            {
                case 1:
                    printf("Please input the Graph series:\n");
                    i = 0;
                    do {
                        scanf("%d%s",&V[i].key,V[i].others);
                    } while(V[i++].key!=-1);
                    i=0;
                    do {
                        scanf("%d%d",&VR[i][0],&VR[i][1]);
                    } while(VR[i++][0]!=-1);
                    VR[i][0] = -1;
                    VR[i][1] = -1;
                    if(CreateCraph(*G_operated,V,VR) == ERROR)
                    {
                        printf("Graph creation failed!\n");
                    }
                    else
                        printf("Graph created successfully!\n");
                    break;

                case 2:
                    if(DestroyGraph(*G_operated) == ERROR)
                    {
                        printf("Graph destruction failed!\n");
                    }
                    else
                        printf("Graph destroyed successfully!\n");
                    break;

                case 3:
                    printf("Please input the key of the vertex to be located:\n");
                    scanf("%d",&key);
                    loc = GetLocation(*G_operated, key);
                    if(loc == -1)
                        printf("Vertex not found!\n");
                    else
                    {
                        printf("Vertex found at index: %d\n", loc);
                        printf("Vertex information: Key: %d, Others: %s\n", G_operated->vertices[loc].data.key, G_operated->vertices[loc].data.others);
                    }
                    break;  

                case 4:
                    printf("Please input the key of the vertex to be modified:\n");
                    scanf("%d",&key);
                    printf("Please input the new information of the vertex:\n");
                    scanf("%d %s", &v.key, v.others);
                    if(PutVex(*G_operated, key, v) == ERROR)
                        printf("Vertex modification failed!\n");
                    else
                        printf("Vertex modified successfully!\n");
                    break;
                
                case 5:
                    printf("Please input the key of the vertex to be found:\n");
                    scanf("%d",&key);
                    first = FirstAdjVex(*G_operated, key);
                    if(first == -1)
                        printf("No adjacent vertex found!\n");
                    else
                    {
                        printf("First adjacent vertex: %d\n", first);
                        printf("Adjacent vertices: %d, %s", G_operated->vertices[first].data.key, G_operated->vertices[first].data.others);
                    }
                        
                    break;

                case 6:
                    printf("Please input the key of the vertex to be found:\n");
                    scanf("%d %d",&key1,&key2);
                    next = NextAdjVex(*G_operated, key1,key2);
                    if(next == -1)
                        printf("No next adjacent vertex found!\n");
                    else
                    {
                        printf("Next adjacent vertex: %d\n", next);
                        printf("Adjacent vertices: %d, %s", G_operated->vertices[next].data.key, G_operated->vertices[next].data.others);
                    }
                        
                    break;

                case 7:
                    printf("Please input the key of the vertex to be inserted:\n");
                    scanf("%d",&v.key);
                    printf("Please input the other information of the vertex:\n");
                    scanf("%s",v.others);
                    if(GetLocation(*G_operated, v.key) != -1)
                    {
                        printf("Vertex already exists!\n");
                        break;
                    }
                    if(InsertVex(*G_operated, v) == ERROR)
                        printf("Vertex insertion failed!\n");
                    else
                        printf("Vertex inserted successfully!\n");
                    break;

                case 8:
                    printf("Please input the key of the vertex to be deleted:\n");
                    scanf("%d",&key);
                    if(DeleteVex(*G_operated, key) == ERROR)
                        printf("Vertex deletion failed!\n");
                    else
                        printf("Vertex deleted successfully!\n");
                    break;

                case 9:
                    printf("Please input the keys of the vertices to be connected:\n");
                    scanf("%d%d",&key,&key1);
                    if(InsertArc(*G_operated, key, key1) == ERROR)
                        printf("Edge insertion failed!\n");
                    else
                        printf("Edge inserted successfully!\n");
                    break;
                
                case 10:
                    printf("Please input the keys of the vertices to be disconnected:\n");
                    scanf("%d%d",&key,&key1);
                    if(DeleteArc(*G_operated, key, key1) == ERROR)
                        printf("Edge deletion failed!\n");
                    else
                        printf("Edge deleted successfully!\n");
                    break;

                case 11:
                    printf("Please input the key of the vertex to be traversed:\n");
                    scanf("%d",&key);
                    if(DFSTraverse(*G_operated, PrintVertex) == ERROR)
                        printf("DFS traversal failed!\n");
                    else
                        printf("DFS traversal completed successfully!\n");
                    break;

                case 12:
                    printf("Please input the key of the vertex to be traversed:\n");
                    scanf("%d",&key);
                    if(BFSTraverse(*G_operated, PrintVertex) == ERROR)
                        printf("BFS traversal failed!\n");
                    else
                        printf("BFS traversal completed successfully!\n");
                    break;

                case 13:
                    printf("Please input the file name to save the graph:\n");
                    scanf("%s",fileName);
                    if(SaveGraph(*G_operated, fileName) == ERROR)
                        printf("Graph saving failed!\n");
                    else
                        printf("Graph saved successfully!\n");
                    break;

                case 14:
                    printf("Please input the file name to load the graph:\n");
                    scanf("%s",fileName);
                    if(LoadGraph(*G_operated, fileName) == ERROR)
                        printf("Graph loading failed!\n");
                    else
                        printf("Graph loaded successfully!\n");
                    break;

                case 15:
                    printf("Please input the key of the vertex and the distance:\n");
                    scanf("%d%d",&key,&k);
                    result = VerticesSetLessThanK(*G_operated, key, k);
                    if(result == NULL)
                        printf("No vertices found!\n");
                    else
                    {
                        printf("Vertices within distance %d from vertex %d:\n", k, key);
                        for(i = 0; result[i].key != -1; i++)
                            printf("%d %s\n", result[i].key, result[i].others);
                    }
                    break;

                case 16:
                    printf("Please input the start and end vertices:\n");
                    scanf("%d%d",&key,&key1);
                    pathLength = ShortestPath(*G_operated, key, key1);
                    if(pathLength == -1)
                        printf("No path found!\n");
                    else
                        printf("Shortest path length: %d\n", pathLength);
                    break;

                case 17:
                    printf("Number of connected components: %d\n", ConnectedComponentsNum(*G_operated));
                    break;

                case 18:
                    printf("Graph adjacency list:\n");
                    PrintGraphList(*G_operated);
                    break;
                
                case 19:
                    printf("Please input the name of the graph to be added:\n");
                    scanf("%s",fileName);
                    if(AddGraph(Graphs, fileName) == ERROR)
                        printf("Graph addition failed!\n");
                    else
                        printf("Graph added successfully!\n");
                    break;

                case 20:
                    printf("Please input the name of the graph to be removed:\n");
                    scanf("%s",fileName);
                    if(RemoveGraph(Graphs, fileName) == ERROR)
                        printf("Graph removal failed!\n");
                    else
                        printf("Graph removed successfully!\n");

                case 21:
                    printf("Please input the name of the graph to be located:\n");
                    scanf("%s",fileName);
                    loc_idx = LocateGraph(Graphs, fileName);
                    if(loc_idx == -1)
                        printf("Graph not found!\n");
                    else
                        printf("Graph found at index: %d\n", loc_idx);
                    break;

                case 22:
                    printf("Graph group:\n");
                    PrintGraphGroup(Graphs);
                    break;

                case 23:
                    printf("Please input the name of the graph to be switched:\n");
                    scanf("%s",fileName);
                    graph_idx = LocateGraph(Graphs, fileName);
                    if(graph_idx == -1)
                        printf("Graph not found!\n");
                    else
                        printf("Switched to graph at index: %d\n", graph_idx);
                    break;

                case 24:
                    printf("Initializing graph group...\n");
                    if(InitGraphGroup(Graphs) == ERROR)
                        printf("Graph group initialization failed!\n");
                    else
                        printf("Graph group initialized successfully!\n");
                    break;

            }

            printf("Press any key to continue...");
            getchar(); // 清除缓冲区中的换行符
            getchar(); // 等待用户输入
        }

        op = 1; // 重置操作码

    }

    return 0; // 返回0表示程序正常结束
}