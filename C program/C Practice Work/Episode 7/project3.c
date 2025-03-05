//程序修改替换
//给定一批整数，以0作为结束标志，建立一个链表，建成一个后进先出链表。

#include <stdio.h>
#include <stdlib.h>
struct s_list{
    int data;
    struct s_list *next;
};
void create_list(struct s_list **headp,int *p);
int main(void){
struct s_list *head=NULL,*p=NULL;
        int s[100] = {1000};
        for(int i=0;i<100;i++)
        {
            scanf("%d",&s[i]);
            if(!s[i]) break;
        }
        create_list(&head,s);
        p=head;
        while (p){
            printf("%d\t",p->data);
            p=p->next;
        }
        printf("\n");
        return 0;  
    }
    //修改create_list函数，使得链表建成一个后进先出链表。
    void create_list(struct s_list **headp,int *p){
        struct s_list *loc_head=NULL,*tail=NULL;
        if(p[0]==0) return;
        else {
            loc_head=(struct s_list *)malloc(sizeof(struct s_list));
            loc_head->data=*p++;
            tail=loc_head;
            while(*p)
            {
                struct s_list *temp = (struct s_list *)malloc(sizeof(struct s_list));
                temp->data=*p++;            //将*p的值赋给暂存节点
                temp->next=loc_head;        //暂存节点指向当前头节点
                loc_head=temp;              //新的头节点为暂存节点
            }
        }
        *headp=loc_head;
    }
