//模块化设计一个成绩统计程序，实现输入，输出，修改指定项，统计平均成绩功能
//输入可以分多次进行
//成绩有4项
//功能4为统计平均成绩并按平均成绩升序排序

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

void PrintList(student *head);
void PrintList_All(student *head);
void AddList(student *headp); 
void ModifyList(student *head, char *id, int num, int score);
void AverageSort(student *head);
void PrintList_Avg(student *head);

int main(void)
{
    student *head = (student *)malloc(sizeof(student)); //创建头节点
    head->name = NULL;
    head->id = NULL;
    head->next = NULL;                                  //初始化头节点
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
                AverageSort(head);                      //成绩可能已经修改，所以需要重新排序
                PrintList(head);
                break;
            case 3:
                scanf("%s %d %d", id_modify, &num, &score);
                ModifyList(head, id_modify, num-1, score);
                break;
            case 4:
                AverageSort(head);                      //成绩可能已经修改，所以需要重新排序
                PrintList_Avg(head);        
                break;
            case 5:
                AverageSort(head);                      //成绩可能已经修改，所以需要重新排序
                PrintList_All(head);
                break;
            case 0:
                return 0;
        }
    }
}

//采用先进先出链表
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
        loc_head->next = temp;                  //将新节点插入到链表尾部
        loc_head = temp;                        //将loc_head指向新的链表尾部
    }
}

//实现平均成绩升序排序,采用交换节点数据域的方式
void AverageSort(student *head)
{
    student *p = head->next;
    student *q = head->next;
    while(p)
    {
        q = p->next;
        while(q)
        {
            if(p->average > q->average)
            {
                char *temp_name = p->name;
                p->name = q->name;
                q->name = temp_name;
                char *temp_id = p->id;
                p->id = q->id;
                q->id = temp_id;
                double temp_average = p->average;
                p->average = q->average;
                q->average = temp_average;
                int temp_score[4];
                for(int i = 0; i < 4; i++)
                {
                    temp_score[i] = p->score[i];
                    p->score[i] = q->score[i];
                    q->score[i] = temp_score[i];
                }
            }
            q = q->next;
        }
        p = p->next;
    }
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
