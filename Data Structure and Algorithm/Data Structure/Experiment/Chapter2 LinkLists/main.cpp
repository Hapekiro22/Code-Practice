#include "def.h"
#include "Link-Lists.h"
#include "Link-Lists-IO.h"
#include "Link-Lists-Addons.h"
#include "Link-Lists-Multi.h"

int main()
{
    int mode = 1;
    int op = 1;

    LinkList *L_operated = NULL;

    LinkList L_single = NULL;

    LISTS Lists;
    InitMultiLists(&Lists);
    int list_idx = 0;
    int loc_idx = 0;

    char fileName[30];
    char Lists_name[30];

    while(mode)
    {
        system("cls");    printf("\n\n");
        printf("          Menu for Mode Selection \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. Single Linked List \n");
        printf("    	  2. Multi Linked List \n");
        printf("    	  0. Exit \n");
        printf("-------------------------------------------------\n\n");
        printf("    Choose the mode from 0 to 2: ");
        scanf("%d",&mode);
        L_operated = NULL; // 重置操作的链表指针
       
        while(op)
        {
            if(mode == 2)
            {
                system("cls");    printf("\n\n");
                printf("-------------------------------------------------\n");
                printf("          Multi-Lists Operation Mode:\n");
                printf("-------------------------------------------------\n"); 
                if(Lists.elem[list_idx] == NULL )
                {
                    printf("                          No lists exist!\n");
                    printf("-------------------------------------------------\n");
                }
                else
                {
                    L_operated = &Lists.elem[list_idx];
                    printf("                  Current list: %s", Lists.name[list_idx]);
                    printf("    List id: %d\n", list_idx + 1);
                    printf("-------------------------------------------------\n");
                }
            }
            else if(mode == 1)
            {
                L_operated = &L_single;
                system("cls");    printf("\n\n");
                printf("-------------------------------------------------\n");
                printf("          Single-Lists Operation Mode:\n");
                printf("-------------------------------------------------\n"); 
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
    
            // 在 while(op) 循环里面添加的代码
            printf("      Menu for Linear Table On Link Structure \n");
            printf("-------------------------------------------------\n");

            // 单链表和多链表通用操作
            printf("    	  1. InitList       7.  LocateElem\n");
            printf("    	  2. DestroyList    8.  PriorElem\n");
            printf("    	  3. ClearList      9.  NextElem \n");
            printf("    	  4. ListEmpty      10. ListInsert\n");
            printf("    	  5. ListLength     11. ListDelete\n");
            printf("    	  6. GetElem        12. ListTraverse\n");

            // 文件操作部分
            printf("-------------------------------------------------\n");
            printf("           File Operation Functions\n");
            printf("-------------------------------------------------\n");
            printf("    	  13. SaveList      14. LoadList\n");

            // 附加功能
            printf("-------------------------------------------------\n");
            printf("           Additional Functions\n");
            printf("-------------------------------------------------\n");
            printf("    	  15. ReverseList   16. SortList\n");
            printf("          17. InitSequenceList\n");

            // 只在多链表模式才显示多链表操作
            if (mode == 2) {
                printf("-------------------------------------------------\n");
                printf("           Multi-Lists Functions\n");
                printf("-------------------------------------------------\n");
                printf("    	  18. AddList      21. LocateList\n");
                printf("    	  19. RemoveList   22. PrintLists\n");
                printf("    	  20. SwitchList   23. InitMultiLists\n");
            }

            printf("-------------------------------------------------\n");
            printf("    	  0. Return to Main Menu\n");
            printf("-------------------------------------------------\n");
            printf("    Choose your operations [0~%d]:", mode == 2 ? 21 : 16);
            scanf("%d", &op);

            if(op == 0)
            {
                printf("Returning to Main Menu...\n");
                op = 1;
                break;
            }

            if(mode == 2 && op != 18 && L_operated == NULL)
            {
                printf("No list exists! Please create a list first.\n");
                op = 1; // 重置操作码
                getchar(); // 清除缓冲区中的换行符
                getchar(); // 等待用户输入
                continue;
            }

            switch(op)
            {
                case 1:
                    if(InitList(L_operated) == OK)
                        printf("InitList successfully!\n");
                    else
                        printf("InitList failed!\n");
                    break;

                case 2:
                    if(DestroyList(L_operated) == OK)
                        printf("DestroyList successfully!\n");
                    if(mode == 2)
                        RemoveList(&Lists, Lists.name[list_idx]);
                    else
                        printf("DestroyList failed!\n");
                    break;
                
                case 3:
                    if(ClearList(L_operated) == OK)
                        printf("ClearList successfully!\n");
                    else
                        printf("ClearList failed!\n");
                    break;
                
                case 4:
                    if(ListEmpty(L_operated) == TRUE)
                        printf("The list is empty!\n");
                    else
                        printf("The list is not empty!\n");
                    break;
                
                case 5:
                    if((list_idx = ListLength(L_operated)) == INFEASIBLE)
                        printf("The list does not exist!\n");
                    else
                        printf("The length of the list is %d\n", list_idx);
                    break;
                
                case 6:
                    int i;
                    ElemType e;
                    printf("Please input the index of the element you want to get: ");
                    scanf("%d", &i);
                    if(GetElem(L_operated, i, &e) == OK)
                        printf("The element at index %d is %d\n", i, e);
                    else
                        printf("GetElem failed!\n");
                    break;
                
                case 7:
                    printf("Please input the element you want to locate: ");
                    scanf("%d", &e);
                    if((i = LocateElem(L_operated, e)) != ERROR)
                        printf("The element %d is located at index %d\n", e, i);
                    else
                        printf("LocateElem failed!\n");
                    break;
                
                case 8:
                    printf("Please input the element you want to find the prior of: ");
                    scanf("%d", &e);
                    ElemType priorElem;
                    if(PriorElem(L_operated, e, &priorElem) == OK)
                        printf("The prior element of %d is found!\n", priorElem);
                    else
                        printf("PriorElem failed!\n");
                    break;
                
                case 9:
                    printf("Please input the element you want to find the next of: ");
                    scanf("%d", &e);
                    ElemType nextElem;
                    if(NextElem(L_operated, e, &nextElem) == OK)
                        printf("The next element of %d is found!\n", nextElem);
                    else
                        printf("NextElem failed!\n");
                    break;

                case 10:
                    printf("Please input the index and the element you want to insert: ");
                    scanf("%d %d", &i, &e);
                    if(ListInsert(L_operated, i, e) == OK)
                        printf("ListInsert successfully!\n");
                    else
                        printf("ListInsert failed!\n");
                    break;

                case 11:
                    printf("Please input the index of the element you want to delete: ");
                    scanf("%d", &i);
                    if(ListDelete(L_operated, i, &e) == OK)
                        printf("ListDelete successfully! Deleted element: %d\n", e);
                    else
                        printf("ListDelete failed!\n");
                    break;
                
                case 12:
                    if(printLists(L_operated) == OK)
                        printf("ListTraverse successfully!\n");
                    else
                        printf("ListTraverse failed!\n");
                    break;
                
                case 13:
                    printf("Please input the file name to save the list: ");
                    scanf("%s", fileName);
                    if(SaveList(L_operated, fileName) == OK)
                        printf("SaveList successfully!\n");
                    else
                        printf("SaveList failed!\n");
                    break;
                
                case 14:
                    printf("Please input the file name to load the list: ");
                    scanf("%s", fileName);
                    if(LoadList(L_operated, fileName) == OK)
                        printf("LoadList successfully!\n");
                    else
                        printf("LoadList failed!\n");
                    break;
                
                case 15:
                    if(reverseList(L_operated) == OK)
                        printf("ReverseList successfully!\n");
                    else
                        printf("ReverseList failed!\n");
                    break;
                
                case 16:
                    if(SortList(L_operated) == OK)
                        printf("SortList successfully!\n");
                    else
                        printf("SortList failed!\n");
                    break;
                
                case 17:
                    printf("Enter a sequence of elements (end with 0): ");
                    if(InitSequenceLists(L_operated) == OK)
                        printf("InitSequenceList successfully!\n");
                    else
                        printf("InitSequenceList failed!\n");
                    break;
                
                case 18:
                    printf("Please input the name of the list you want to add: ");
                    scanf("%s", Lists_name);
                    if(AddList(&Lists, Lists_name) == OK)
                        printf("AddList successfully!\n");
                    else
                        printf("AddList failed!\n");
                    break;
                
                case 19:
                    printf("Please input the name of the list you want to remove: ");
                    scanf("%s", Lists_name);
                    if(RemoveList(&Lists, Lists_name) == OK)
                        printf("RemoveList successfully!\n");
                    else
                        printf("RemoveList failed!\n");
                    break;
                
                case 20:
                    printf("Please input the name of the list you want to switch to: ");
                    scanf("%s", Lists_name);
                    if((list_idx = LocateList(Lists, Lists_name)) != ERROR)
                        printf("SwitchList successfully!\n");
                    else
                        printf("SwitchList failed!\n");
                    break;
                
                case 21:
                    printf("Please input the name of the list you want to locate: ");
                    scanf("%s", Lists_name);
                    if((loc_idx = LocateList(Lists, Lists_name)) != ERROR)
                        printf("LocateList successfully! List id: %d\n", loc_idx + 1);
                    else
                        printf("LocateList failed!\n");
                    break;
                
                case 22:
                    PrintLists(Lists);
                    break;
                
                case 23:
                    if(InitMultiLists(&Lists) == OK)
                        printf("InitMultiLists successfully!\n");
                    else
                        printf("InitMultiLists failed!\n");
                    break;
            }

            printf("Press any key to continue...");
            getchar(); // 清除缓冲区中的换行符
            getchar(); // 等待用户输入
 
        }
        
        op = 1; // 重置操作码
    
    }

    return 0;
}
