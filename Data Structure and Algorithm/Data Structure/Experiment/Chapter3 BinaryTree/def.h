#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define INIT_TREE_NUM 20
#define INIT_TREE_SIZE 100

typedef int status;
typedef int KeyType; 
typedef struct {
		KeyType  key;
		char others[20];
} TElemType; //二叉树结点类型定义


typedef struct BiTNode{  //二叉链表结点的定义
		TElemType  data;
		struct BiTNode *lchild,*rchild;
} BiTNode, *BiTree;

typedef struct BiTrees {
	BiTree Trees[INIT_TREE_NUM]; // 二叉树数组
	int num; // 二叉树数量
	char name[INIT_TREE_NUM][20]; // 二叉树名称
} BiTrees;

//status SaveBiTree(BiTree T, char FileName[]);
//status LoadBiTree(BiTree &T, char FileName[]);