#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Def.h"
#include "Lists.h"
#include "Lists-File-IO.h"
#include "Lists-Multi.h"

void main(void){
   SqList L;  int op=1;

   LISTS Lists;
   Lists.length = 0;
   Lists.listsize = LIST_INIT_SIZE;

   while(op){
      system("cls");	printf("\n\n");
      printf("      Menu for Linear Table On Sequence Structure \n");
      printf("-------------------------------------------------\n");
      printf("    	  1. InitList       7. LocateElem\n");
      printf("    	  2. DestroyList    8. PriorElem\n");
      printf("    	  3. ClearList      9. NextElem \n");
      printf("    	  4. ListEmpty      10. ListInsert\n");
      printf("    	  5. ListLength     11. ListDelete\n");
      printf("    	  6. GetElem        12. InitSequenceList\n");
      printf("-------------------------------------------------\n\n");
      printf("      Menu for Add-on lists function");
      printf("-------------------------------------------------\n");
      printf("    	  13. ListFWrite    17. ListFRead\n");
      printf("    	  14. AddList       18. RemoveList\n");
      printf("    	  15. LocateList    19. MaxSubArray\n");
      printf("    	  16. SubArrayNum   20. Sortlist\n");
      printf("-------------------------------------------------\n\n");
      printf("    	  0. Exit\n");
      printf("-------------------------------------------------\n");
      printf("    请选择你的操作[0~12]:");
      scanf("%d",&op);

      switch(op)
      {
         case 1: 
            if(InitList(L) == OK)
               printf("InitList OK\n");
            else
               printf("InitList ERROR\n");
            break;
         case 2:
            if(DestroyList(L) == OK)
               printf("DestroyList OK\n");
            else
               printf("DestroyList ERROR\n");
            break;
         case 3:
            if(ClearList(L) == OK)
               printf("ClearList OK\n");
            else
               printf("ClearList ERROR\n");
            break;
         case 4:
            if(ListEmpty(L) == TRUE)
               printf("List is empty!\n");
            if(ListEmpty(L) == FALSE)
               printf("List is not empty!\n");
            if(ListEmpty(L) == INFEASIBLE)
               printf("List is not exist!\n");
            break;
         case 5:
            if((ListLength(L)) != INFEASIBLE)
               printf("List length is %d\n",ListLength(L));
            else
               printf("List is not exist!\n");
            break;
         case 6:
            {
               int i; ElemType e;
               printf("请输入要获取的元素位置:");
               scanf("%d",&i);
               if(GetElem(L,i,e) == OK)
                  printf("GetElem OK, the element is %d\n",e);
               else
                  printf("GetElem ERROR\n");
            }
            break;
         case 7:
            {
               int i; ElemType e;
               printf("请输入要查找的元素:");
               scanf("%d",&e);
               if(LocateElem(L,e) != 0)
                  printf("LocateElem OK, the element is %d\n",LocateElem(L,e));
               else
                  printf("LocateElem ERROR\n");
            }
            break;
         case 8:
            {
               int i; ElemType e;
               printf("请输入要查找的元素位置:");
               scanf("%d",&i);
               if(PriorElem(L,i,e) == OK)
                  printf("PriorElem OK, the element is %d\n",e);
               else
                  printf("PriorElem ERROR\n");
            }
            break;
         case 9:
            {
               int i; ElemType e;
               printf("请输入要查找的元素位置:");
               scanf("%d",&i);
               if(NextElem(L,i,e) == OK)
                  printf("NextElem OK, the element is %d\n",e);
               else
                  printf("NextElem ERROR\n");
            }
            break;
         case 10:
            {
               int i; ElemType e;
               printf("请输入要插入的元素位置:");
               scanf("%d",&i);
               printf("请输入要插入的元素:");
               scanf("%d",&e);
               if(ListInsert(L,i,e) == OK)
                  printf("ListInsert OK\n");
               else
                  printf("ListInsert ERROR\n");
            }
            break;
         case 11:
            {
               int i; ElemType e;
               printf("请输入要删除的元素位置:");
               scanf("%d",&i);
               if(ListDelete(L,i,e) == OK)
                  printf("ListDelete OK, the element is %d\n",e);
               else
                  printf("ListDelete ERROR\n");
            }
            break;
         case 12:
            if(ListTraverse(L) == OK)
               printf("ListTraverse OK\n");
            else
               printf("ListTraverse ERROR\n");
            break;
         case 13:
            {
               char filename[20];
               printf("请输入文件名:");
               scanf("%s",filename);
               ListWrite(&L,filename);
            }
            break;
         case 14:
            {
               char filename[20];
               printf("请输入文件名:");
               scanf("%s",filename);
               ListRead(&L,filename);
            }
            break;

         case 15:
            {
               char ListName[20];
               printf("请输入要添加的线性表名称:");
               scanf("%s",ListName);
               if(AddList(Lists,ListName) == OK)
                  printf("AddList OK\n");
               else
                  printf("AddList ERROR\n");
            }
      }

         
         
         
      }
}