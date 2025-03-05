//插入排序

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char *name;
    char *id;
    int score[4];
    double average;
    struct student *next;
}student;

void AddList(student *headp); 
void ModifyList(student *head, char *id, int num, int score);
void AverageList(student *head);
void PrintList(student *head);
void PrintList_All(student *head);
void PrintList_Avg(student *head);

int main(void)
{
    student *head = (student *)malloc(sizeof(student));
    head->name = NULL;
    head->id = NULL;
    head->next = NULL;
    int num,score;
    int mode;
    char *id_modify = (char *)malloc(20 * sizeof(char)); 
    while(1)
    {
        scanf("%d", &mode);
        switch(mode)
        {
            case 1:
                AddList(head);
                break;
            case 2:
                AverageList(head);                                  //任何的输出前都要重算平均成绩
                PrintList(head);
                break;
            case 3:
                scanf("%s %d %d", id_modify, &num, &score);
                ModifyList(head, id_modify, num-1, score);          //可能导致顺序改变
                break;
            case 4:
                AverageList(head);
                PrintList_Avg(head);
                break;
            case 5:
                AverageList(head);
                PrintList_All(head);
                break;
            case 0:
                return 0;
        }
    }
}

//采用先进先出链表，不额外创建链表，这样第一次和第二次的情况都可以处理
void AddList(student *headp)
{
    student *loc_head = NULL;
    //先将loc_head指向当前链表的最后一个节点,当只有一个节点时，loc_head指向headp
    for(loc_head = headp; loc_head->next != NULL; loc_head = loc_head->next);  
    student *tail = NULL;
    int num = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        student *temp  = (student *)malloc(sizeof(student));
        temp->name = (char *)malloc(50 * sizeof(char)); 
        temp->id = (char *)malloc(20 * sizeof(char)); 
        scanf("%s %s %d %d %d %d", temp->id, temp->name, &temp->score[0], &temp->score[1], &temp->score[2], &temp->score[3]);
        temp->average = (temp->score[0] + temp->score[1] + temp->score[2] + temp->score[3]) / 4.0;
        temp->next = NULL;
        loc_head->next = temp;
        loc_head = temp;
    }
}

void ModifyList(student *head, char *id_m, int num, int score)
{
    student *p = head->next;
    while(p)
    {
        if(strcmp(p->id, id_m) == 0)
        {
            p->score[num] = score;
            p->average = (p->score[0] + p->score[1] + p->score[2] + p->score[3]) / 4.0;
            break;
        }
        p = p->next;
    }
}

//实现平均成绩升序排序,用改变节点连接方式的方法
void AverageList(student *head)
{
    if (head == NULL || head->next == NULL)
        return;
    student *sorted = NULL;                             //初始化一个新的链表
    student *current = head->next;
    while (current != NULL)
    {
        student *next = current->next;                  //保存当前节点的下一个节点
        if (sorted == NULL || sorted->average >= current->average)     //如果新链表为空或者新链表的头节点的平均成绩大于等于当前节点的平均成绩
        {
            current->next = sorted; 
            sorted = current;                           //将当前节点插入到新链表的头部
        }
        else                        
        {
            student *temp = sorted;
            while (temp->next != NULL && temp->next->average < current->average)
                    temp = temp->next;                  //找到新链表中第一个平均成绩大于当前节点的节点
            current->next = temp->next;             
            temp->next = current;                       //将当前节点插入到新链表中
        }
        current = next;
    }
    head->next = sorted;
}

void PrintList(student *head)
{
    student *p = head->next;
    while(p != NULL)
    {
        printf("%s %s %d %d %d %d\n", p->id, p->name, p->score[0], p->score[1], p->score[2], p->score[3]);
        p = p->next;
    }
}

void PrintList_All(student *head)
{
    student *p = head->next;
    while(p)
    {
        printf("%s %s %d %.2lf\n", p->id, p->name,(p->score[0]+p->score[1]+p->score[2]+p->score[3]), p->average);
        p = p->next;
    }
}

void PrintList_Avg(student *head)
{
    student *p = head->next;
    while(p)
    {
        p->average = (p->score[0] + p->score[1] + p->score[2] + p->score[3]) / 4.0;
        printf("%s %s %.2lf\n", p->id, p->name, p->average);
        p = p->next;
    }
}
