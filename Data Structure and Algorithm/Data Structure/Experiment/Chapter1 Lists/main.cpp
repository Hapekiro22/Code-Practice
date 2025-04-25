#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Def.h"
#include "Lists.h"
#include "Lists-File-IO.h"
#include "Lists-Multi.h"
#include "Add-on-lists.h"

int main(void){

   SqList *L;   
   SqList singleL;
   singleL.elem = NULL;
   
   int op=1;

   int multilist = 1;
   int lidx = 0;
   LISTS Lists;
   Lists.length = 0;
   Lists.listsize = LIST_INIT_SIZE;

   while(multilist)
   {
      printf("------------Mode Selecting--------------\n");
      printf("    1.Single-Lists\n    2.Multi-Lists\n    0.exit\n");
      scanf("%d",&multilist);
      if(multilist == 0) break;
      op = 1;

      while(op){

         system("cls");
         if(multilist == 2)
         {
            printf("Multi-Lists Operating Mode:\n\n");
            if(lidx < 0)
            {
               printf("No list now!");
            }
            else
            {
               printf("Current List Name: %s\n",Lists.elem[lidx].name);
               L = &Lists.elem[lidx].L;
            } 
         }

         else  
            L = &singleL;
      	printf("\n\n");
         printf("      Menu for Linear Table On Sequence Structure \n");
         printf("-------------------------------------------------\n");
         printf("    	  1. InitList       7. LocateElem\n");
         printf("    	  2. DestroyList    8. PriorElem\n");
         printf("    	  3. ClearList      9. NextElem \n");
         printf("    	  4. ListEmpty      10. ListInsert\n");
         printf("    	  5. ListLength     11. ListDelete\n");
         printf("    	  6. GetElem        12. ListTrabverse\n");
         printf("-------------------------------------------------\n\n");
         printf("      Menu for Add-on lists function\n");
         printf("-------------------------------------------------\n");
         printf("    	  13. ListFWrite    14. ListFRead\n");
         printf("    	  15. MaxsubArray   16. SubArrayNumt\n");
         printf("    	  17. Sortlist    \n");
         printf("-------------------------------------------------\n\n");
         printf("      Menu for Multi-Lists Operating Mode\n");
         printf("-------------------------------------------------\n");
         printf("    	  18. AddList      19. RemoveList\n");
         printf("    	  20. LocateList   21. ShowList \n");
         printf("    	  0. Exit\n");
         printf("-------------------------------------------------\n");
         printf("    Choose operation:[0~20]:");
         scanf("%d",&op);

         if(!(*L).elem && 0)
            printf("error!\n");

         switch(op)
         {
            case 1: 
               if(InitList(L) == OK)
                  printf("InitList OK\n");
               else
                  printf("InitList ERROR\n");
               
               //printf("Pre input the list?\n");
               char c;
               //if((c = getchar()) == '1')
               //InputList(L);
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
                  printf("Please input the location of the element:");
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
                  printf("Please input the element to be located:");
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
                  printf("Please input the element to be located:");
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
                  printf("Please input the element to be located:");
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
                  printf("Please input the location to be inserted:");
                  scanf("%d",&i);
                  printf("Please input the element to be inserted:");
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
                  printf("Please input the location to be deleted:");
                  scanf("%d",&i);
                  if(ListDelete(L,i,e) == OK)
                     printf("ListDelete OK, the element is %d\n",e);
                  else
                     printf("ListDelete ERROR\n");
               }
               break;

            case 12:
               if(ListTraverse(L) == OK)
                  printf("\nListTraverse OK\n");
               else
                  printf("ListTraverse ERROR\n");
               break;

            case 13:
               {
                  char filename[20];
                  printf("Please input the file name:");
                  scanf("%s",filename);
                  ListFWrite(L,filename);break;

               }
               
            case 14:
               {
                  char filename[20];
                  printf("Please input the file name:");
                  scanf("%s",filename);
                  ListFRead(L,filename);break;
               }
               

            case 15:
               {
                  ElemType e;
                  e = MaxSubArray(L);
                  printf("MaxsubArray OK, the element is %d\n",e);
                  break;
               }
            
            case 16:
               {
                  int k;
                  printf("Input k:");
                  scanf("%d",&k);
                  int count = SubArrayNum(L,k);
                  printf("SubArrayNum OK, the element is %d\n",count);
                  break;
               }
            
            case 17:
               {
                  SortList(L);
                  printf("SortList OK\n");
                  for(int i = 0; i < L->length; i++)
                  {
                     if(i != L->length - 1)
                        printf("%d ",L->elem[i]);
                     else
                        printf("%d",L->elem[i]);
                  }
                  printf("\n");
                  break;
               }
            
            case 18:
               {
                  printf("Please input the name of the lists:\n");
                  char nameadd[30];
                  scanf("%s",nameadd);
                  AddList(&Lists, nameadd);
                  break;
               }

            case 19:
               {
                  printf("Please input the name of the list to be removed:\n");
                  char namerm[30];
                  scanf("%s", namerm);
                  RemoveList(&Lists, namerm);
                  break;
               }

            case 20:
               {
                  printf("Please input the list name to be located:\n");
                  char namelc[30];
                  scanf("%s",namelc);
                  int id = LocateList(&Lists, namelc);
                  printf("The located list id is:%d\n",id);
                  printf("Switch to the new list? (1/0)\n");
                  bool sw = false;
                  scanf("%d",&sw);
                  if(sw)
                     lidx = id;
                  break;
               }
            
            case 21:
               {
                  ShowList(&Lists);
               }
            
         } 



         if(op)
         {
            getchar();
            printf("Continue?(\\n)");
            getchar();
         }

      }
   }
   


}