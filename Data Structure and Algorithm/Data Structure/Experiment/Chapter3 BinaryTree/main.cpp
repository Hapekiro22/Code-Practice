
#include "def.h"
#include "BinaryTree.h"
#include "BiTree-Traverse.h"
#include "BiTree-IO.h"
#include "BiTree-Addons.h"
#include "BiTree-Multi.h"

extern int count_def; // 全局变量，用于跟踪前序遍历序列的当前位置

int main()
{
    int mode = 1, op = 1,count = 0,temp = 0; // 操作码
    BiTree *T_operated = NULL;
    BiTree T_single = NULL; // 单棵二叉树指针
    BiTrees Trees;
    InitBiTrees(Trees); // 初始化多棵二叉树

    DEF definition[100]; // 定义数组

    char fileName[30];
    char name[20];  

    int tree_idx = 0;
    int tree_depth = 0;

    KeyType key, old_key, sibling_key, insert_after_key, delete_key, first_key, second_key;
    BiTNode *node = NULL;
    BiTNode *sibling = NULL;
    BiTNode *lca = NULL;
    TElemType new_value, new_node_value;
    int LR;
    int index;

    int i,j,k,flag = 1;

    while(mode)
    {
        system("cls");    printf("\n\n");
        printf("          Menu for Mode Selection \n");
        printf("------------------------------------------------------\n");
        printf("    	  1. Single Binary Tree \n");
        printf("    	  2. Multi Binary Tree \n");
        printf("    	  0. Exit \n");
        printf("------------------------------------------------------\n");
        printf("    Choose the mode from 0 to 2: ");
        scanf("%d",&mode);
        T_operated = NULL; // 重置操作的链表指针
       
        while(op)
        {

            count_def = 0; // 重置前序遍历序列的当前位置

            if(mode == 2)
            {
                system("cls");    printf("\n\n");
                printf("------------------------------------------------------\n");
                printf("          Multi-BiTrees Operation Mode:\n");
                printf("------------------------------------------------------\n"); 
                if(Trees.name[tree_idx][0] == 0)
                {
                    T_operated = NULL;
                    printf("                          No trees exists!\n");
                    printf("------------------------------------------------------\n");
                }
                else
                {
                    T_operated = &(Trees.Trees[tree_idx]);
                    printf("                  Current list: %s", Trees.name[tree_idx]);
                    printf("    List id: %d", tree_idx + 1);
                    if(Trees.Trees[tree_idx] == NULL)
                    printf("  (Uinit)");
                    printf("\n------------------------------------------------------\n");
                }
            } 
            else if(mode == 1)
            {
                T_operated = &T_single;
                system("cls");    printf("\n\n");
                printf("---------------------------------------------------------\n");
                printf("          Single-Tree Operation Mode:\n");
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
            printf("    	  1. CreateBiTree           8. GetSibling\n");
            printf("    	  2. DestroyBiTree          9. InsertNode\n");
            printf("    	  3. ClearBiTree            10. DeleteNode\n");
            printf("    	  4. BiTreeEmpty            11. PreOrderTrav\n");
            printf("    	  5. BiTreeDepth            12. InOrderTrav\n");
            printf("    	  6. LocateNode             13. PostOrderTrav\n");
            printf("    	  7. Assign                 14. LevelOrderTrav\n");
            printf("---------------------------------------------------------\n");
            printf("         File Operation Menu \n");
            printf("---------------------------------------------------------\n");
            printf("    	  15. SaveBiTree            16. LoadBiTree\n");
            printf("---------------------------------------------------------\n");
            printf("         Additional Functions Menu \n");
            printf("---------------------------------------------------------\n");
            printf("    	  17. MaxPathSum  19. InvertTree\n");
            printf("          18. LowestCommonAncestor\n");
            printf("---------------------------------------------------------\n");

            if(mode == 2)
            {
                printf("         Multi-BiTrees Operation Selection \n");
                printf("---------------------------------------------------------\n");
                printf("    	  20. AddBiTree             23. DeleteBiTree\n");
                printf("    	  21. LocateBiTree          24. PrintBiTrees\n");
                printf("    	  22. ClearBiTrees          25. InitBiTrees \n");
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

            if(mode == 2 && op != 20 && op != 22 && op != 24 && T_operated == NULL)
            {
                printf("No trees exist! Please create a tree first.\n");
                op = 1; // 重置操作码
                getchar(); // 清除缓冲区中的换行符
                getchar(); // 等待用户输入
                continue;
            }

            switch(op)
            {
                    case 1:
                        printf("Please input the definition of the tree (end with 0): ");
                        i = 0;
                        do {
                            scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
                        } while (definition[i++].pos);

                        while(definition[j].pos) // 去掉最后一个0
                        {
                            printf("definition[%d]: %d %d %s\n", j, definition[j].pos, definition[j].data.key, definition[j].data.others);
                            j++;
                        }

                        if(!flag)
                        {
                            printf("Duplicate key found! Please re-enter the definition.\n");
                            flag = 1; // 重置标志
                            break; // 重新输入定义
                        }

                        if(CreateBiTree(T_operated, definition) == OK)
                            printf("Create Tree Successfully!\n"); // 创建二叉树
                        else
                            printf("Create Tree Failed!\n"); // 创建失败
                        break;
                    
                    case 2:
                        if(ClearBiTree(T_operated) == OK)
                            printf("Destroy Tree Successfully!\n"); // 销毁二叉树
                        else
                            printf("Destroy Tree Failed!\n"); // 销毁失败
                        break;
                    
                    case 3:
                        if(ClearBiTree(T_operated) == OK)
                            printf("Clear Tree Successfully!\n"); // 清空二叉树
                        else
                            printf("Clear Tree Failed!\n"); // 清空失败
                        break;
                    
                    case 4:
                        if(BiTreeEmpty(*T_operated) == TRUE)
                            printf("The tree is empty!\n"); // 二叉树为空
                        else
                            printf("The tree is not empty!\n"); // 二叉树不为空
                        break;
                    
                    case 5:
                        if((tree_depth = BiTreeDepth(*T_operated)) == INFEASIBLE)
                            printf("The tree does not exist!\n"); // 二叉树不存在
                        else
                            printf("The depth of the tree is: %d\n", tree_depth); // 输出二叉树深度
                        break;

                    case 6:
                        printf("Please input the key of the node you want to locate: ");
                        scanf("%d", &key);
                        node = LocateNode(*T_operated, key); // 查找节点
                        if(node != NULL)
                            printf("Node found! Node: %d,%s\n", node->data.key,node->data.others); // 节点存在
                        else
                            printf("Node not found!\n"); // 节点不存在
                        break;
                    
                    case 7:
                        printf("Please input the key of the node you want to assign: ");
                        scanf("%d", &old_key);
                        printf("Please input the new value (key and others): ");
                        scanf("%d %s", &new_value.key, new_value.others);
                        if(Assign(T_operated, old_key, new_value) == OK)
                            printf("Assign Successfully!\n"); // 赋值成功
                        else
                            printf("Assign Failed!\n"); // 赋值失败
                        break;

                    case 8:
                        printf("Please input the key of the node you want to get its sibling: ");
                        scanf("%d", &sibling_key);
                        sibling = GetSibling(*T_operated, sibling_key); // 获取兄弟节点
                        if(sibling != NULL)
                            printf("Sibling found! Sibling: %d,%s\n", sibling->data.key,sibling->data.others); // 兄弟节点存在
                        else
                            printf("Sibling not found!\n"); // 兄弟节点不存在
                        break;

                    case 9:
                        printf("Please input the key of the node you want to insert after: ");
                        scanf("%d", &insert_after_key);
                        printf("Please input 0 for left child or 1 for right child: ");
                        scanf("%d", &LR);
                        printf("Please input the new node value (key and others): ");
                        scanf("%d %s", &new_node_value.key, new_node_value.others);
                        if(InsertNode(T_operated, insert_after_key, LR, new_node_value) == OK)
                            printf("Insert Node Successfully!\n"); // 插入节点成功
                        else
                            printf("Insert Node Failed!\n"); // 插入节点失败
                        break;
                    
                    case 10:
                        printf("Please input the key of the node you want to delete: ");
                        scanf("%d", &delete_key);
                        if(DeleteNode(T_operated, delete_key) == OK)
                            printf("Delete Node Successfully!\n"); // 删除节点成功
                        else
                            printf("Delete Node Failed!\n"); // 删除节点失败
                        break;

                    case 11:
                        PreOrderTraverse(*T_operated,ShowNode); // 前序遍历
                        break;
                    
                    case 12:
                        InOrderTraverse(*T_operated,ShowNode); // 中序遍历
                        break;
                    
                    case 13:
                        PostOrderTraverse(*T_operated,ShowNode); // 后序遍历
                        break;
                    
                    case 14:
                        LevelOrderTraverse(*T_operated,ShowNode); // 层序遍历
                        break;

                    case 15:
                        printf("Please input the file name to save the tree: ");
                        scanf("%s", fileName);
                        if(SaveBiTree(*T_operated, fileName) == OK)
                            printf("SaveBiTree Successfully!\n"); // 保存二叉树成功
                        else
                            printf("SaveBiTree Failed!\n"); // 保存二叉树失败
                        break;

                    case 16:
                        printf("Please input the file name to load the tree: ");
                        scanf("%s", fileName);
                        if(LoadBiTree(T_operated, fileName) == OK)
                            printf("LoadBiTree Successfully!\n"); // 加载二叉树成功
                        else
                            printf("LoadBiTree Failed!\n"); // 加载二叉树失败
                        break;

                    case 17:
                        printf("MaxPathSum: %d\n", MaxPath(*T_operated)); // 最大路径和
                            printf("MaxPathSum Successfully!\n"); // 最大路径和成功
                        break;
                    
                    case 18:
                        printf("Please input the key of the first node: ");
                        scanf("%d", &first_key);
                        printf("Please input the key of the second node: ");
                        scanf("%d", &second_key);
                        lca = LowestCommonAncestor(*T_operated, first_key, second_key); // 最近公共祖先
                        if(lca != NULL)
                            printf("Lowest Common Ancestor found! LCA: %d,%s\n", lca->data.key,lca->data.others); // 最近公共祖先存在
                        else
                            printf("Lowest Common Ancestor not found!\n"); // 最近公共祖先不存在
                        break;

                    case 19:
                        if(InvertTree(T_operated) == OK)
                            printf("Invert Tree Successfully!\n"); // 反转二叉树成功
                        else
                            printf("Invert Tree Failed!\n"); // 反转二叉树失败
                        break;
                    
                    case 20:
                        printf("Please input the name of the new tree: ");
                        scanf("%s", name);
                        if(AddBiTree(Trees, name) == OK)
                            printf("AddBiTree Successfully!\n"); // 添加二叉树成功
                        else
                            printf("AddBiTree Failed!\n"); // 添加二叉树失败
                        break;

                    case 21:
                        printf("Please input the name of the tree you want to locate: ");
                        scanf("%s", name);
                        index = LocateBiTree(Trees, name); // 查找二叉树
                        if(index != -1)
                        {
                            printf("Tree found! Tree: %s\n", Trees.name[index]); // 二叉树存在
                            tree_idx = index; // 更新当前树索引
                        }
                        else
                            printf("Tree not found!\n"); // 二叉树不存在
                        break;
                    
                    case 22:
                        if(ClearBiTrees(Trees) == OK)
                            printf("Clear BiTrees Successfully!\n"); // 清空多棵二叉树成功
                        else
                            printf("Clear BiTrees Failed!\n"); // 清空多棵二叉树失败
                        break;

                    case 23:
                        printf("Please input the name of the tree you want to delete: ");
                        scanf("%s", name);
                        if(DeleteBiTree(Trees, name) == OK)
                            printf("Delete BiTree Successfully!\n"); // 删除二叉树成功
                        else
                            printf("Delete BiTree Failed!\n"); // 删除二叉树失败
                        break;

                    case 24:
                        if(PrintBiTrees(Trees) == OK)
                            printf("Print BiTrees Successfully!\n"); // 打印多棵二叉树成功
                        else
                            printf("Print BiTrees Failed!\n"); // 打印多棵二叉树失败
                        break;
                    
                    case 25:
                        if(InitBiTrees(Trees) == OK)
                            printf("Init BiTrees Successfully!\n"); // 初始化多棵二叉树成功
                        else
                            printf("Init BiTrees Failed!\n"); // 初始化多棵二叉树失败
                        break;
                    
                    default:
                        printf("Invalid operation!\n"); // 无效操作
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