#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR -1
#define INFEASIBLE -3
#define OVERFLOW -2
#define MAX_LISTS_NUM 20

typedef int status;
typedef int ElemType; //数据元素类型定义

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef int ElemType;
typedef struct LNode{  //单链表（链式结构）结点的定义
      ElemType data;
      struct LNode *next;
    }LNode,*LinkList;

typedef struct LISTS {
    LinkList *elem = NULL;
    char **name;
    int length;
    int listsize;
} LISTS; 