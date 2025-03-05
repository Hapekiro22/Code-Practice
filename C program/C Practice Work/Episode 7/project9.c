//利用值栈求逆波兰表达式的值
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct n_list
{
    int data;
    struct n_list *next;
    struct n_list *pre;                         //双向链表，用于返回上一层
}n_list;

int Calculate(char *s);
int turnNum(char *s, int *i);                   //将字符串转换为数字

int main(void)
{
    char s[MAX];
    fgets(s, MAX, stdin);                       //读取一行字符串，包括空格
    s[strcspn(s, "\n")] = '\0';                 //去掉换行符 
    int result = Calculate(s);
    printf("%d\n", result);
    return 0;
}

int Calculate(char *s)
{
    n_list *head = (n_list *)malloc(sizeof(n_list));
    head->next = NULL;
    head->pre = NULL;
    n_list *p = head;
    int a,b,flag = 0;
    if(s[0]=='\0') return 0;
    else
    {
        for(int i = 0;s[i] != '\0'; i++)
        {
            if(s[i]=='-'&&s[i+1]>='0'&&s[i+1]<='9')             //判断负数，且不是减号
            {
                flag = 1;                                   
                continue;                                       //跳过负号
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                int num = turnNum(s,&i);
                if(flag)                                        //负数，取反
                {
                    num = -num;
                    flag = 0;
                }
                p->next = (n_list *)malloc(sizeof(n_list));
                p->data = num;
                n_list *temp = p;
                p = p->next;
                p->pre = temp;                                  
            }
            else if(s[i]!=' ')
            {
                a = p->pre->data;                           //取出栈顶两个数
                b = p->pre->pre->data;      
                switch(s[i])
                {
                    case '+':
                        p->pre->pre->data = a + b;
                        break;
                    case '-':
                        p->pre->pre->data = b - a;
                        break;
                    case '*':
                        p->pre->pre->data = a * b;
                        break;
                    case '/':
                        p->pre->pre->data = b / a;
                        break;
                }
                p = p->pre;                                 //栈顶指针指向栈顶，即本次计算后的下一个数
            }
        }
    }
    return p->pre->data;                                    //注意p指向结果的下一个数，所以返回p->pre
}

int turnNum(char *s, int *i)                                //采用*i方便直接跳过一串数字
{
    int num = 0;
    while(s[*i]>='0'&&s[*i]<='9')
    {
        num = num * 10 + s[*i] - '0';
        (*i)++;
    }
    return num;
}