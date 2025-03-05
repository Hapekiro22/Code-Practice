//任务树生成

#include <stdio.h>
#include <stdlib.h>
#define N 5000

typedef struct task
{
    int num,prevNum;
    int *prevTask;
}task;                          
//任务不必构造链表，因为编号是线性的，按编号读取就好

void TaskSearch(task *end,int *TodoList,task **TaskIndex);
void PrintTaskList(task **TaskIndex,int n);

int main()
{
    FILE *fp;
    fp = fopen("task/task2.in","r");
    int n,count = 0;
    fscanf(fp,"%d",&n);
    task **TaskIndex = (task **)malloc(n*sizeof(task*));
    //存储前置任务列表
    for(int i = 0;i < n;i++)
    {   
        int prevNum;
        fscanf(fp,"%d",&prevNum);
        *(TaskIndex + i) = (task *)malloc(sizeof(task));
        task *p = *(TaskIndex + i);
        p -> num = i + 1;
        p -> prevNum = prevNum;
        if(prevNum == 0)
        {
            p -> prevTask = (int *)malloc(sizeof(int));
            *(p -> prevTask) = -1;                          //起始任务
        }
        else
        {
            p -> prevTask = (int *)malloc(prevNum*sizeof(int));
            for(int j = 0;j < prevNum;j++)
                fscanf(fp,"%d",p -> prevTask + j);
        }            
    }
    //PrintTaskList(TaskIndex,n);

    int *TodoList = (int *)malloc(n * sizeof(int));         //标记数组
    for(int i = 0;i < n;i++)
        *(TodoList + i) = 0;
    TaskSearch(*(TaskIndex),TodoList,TaskIndex);
    for(int i = 0;i < n;i++)
        if(*(TodoList + i))
            count++;
    printf("%d\n",count+1);

    free(TaskIndex);
    free(TodoList);
    return 0;
}

//深度优先搜索，搜索完一个点就返回一个待完成的任务集，然后将任务集进一步调用
void TaskSearch(task *end,int *TodoList,task **TaskIndex)
{
    int num = end -> prevNum;
    //printf("TodoList:");
    if(num == 0)
    {
        //printf("Find the end task %d\n",end -> num);
        *(TodoList + end -> num - 1) += 1;
        return;
    }
    for(int i = 0;i < num;i++)
        //printf("%d ",*(end -> prevTask + i));
    //printf("\n");
    for(int i = 0;i < num;i++)
    {
        if(*(TodoList + *(end -> prevTask + i) - 1) == 0)           //如果任务未被记录
        {
            *(TodoList + *(end -> prevTask + i) - 1) += 1;          //记录当前要做的任务
            TaskSearch(*(TaskIndex + *(end -> prevTask + i) - 1),TodoList,TaskIndex);   //进入下一级搜索
        }
    }
    return;
}

void PrintTaskList(task **TaskIndex,int n)
{
    for(int i = 0;i < n;i++)
    {
        printf("Task %d requires ",i + 1);
        for(int j = 0;j < (*(TaskIndex + i)) -> prevNum;j++)
            printf("%d ",*((*TaskIndex[i]).prevTask + j));
        printf("\n");
    }
    return;
}