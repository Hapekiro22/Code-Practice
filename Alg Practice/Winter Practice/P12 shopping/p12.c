//商品列表与客户需求对照
//当客户的需求码与商品码的末位序列相同时，称为匹配
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000000000

typedef struct Customer
{
    long RequestSeries;
    int SeriesCount;
    long TargetedSeries;
    struct Customer *next;
}Customer;

typedef struct Book
{
    long BookSeries;
    struct Book *next;
}Book;

//单个客户的需求码与商品码的匹配
void SearchBook(Book *BookList,Customer *Customs)
{
    Book *p = BookList;
    for(;p != NULL;p = p->next)
    {
        int checknum = pow(10,Customs->SeriesCount);
        //printf("checknum = %d ",checknum);
        //printf("p->BookSeries = %ld ",p->BookSeries);
        //printf("Customs->RequestSeries = %ld ",Customs->RequestSeries);
        if(p->BookSeries % checknum == Customs->RequestSeries)
        {
            //printf("Customer %ld's request %ld is matched with book %ld\n",Customs->RequestSeries,Customs->RequestSeries,p->BookSeries);
            if(Customs->TargetedSeries > p->BookSeries)
            {
                Customs->TargetedSeries = p->BookSeries;
            }
        }
    }
    if(Customs->TargetedSeries == MAX)
        Customs->TargetedSeries = -1;
    return;
}

void CreateCustomerList(Customer *Customs,int num1)
{
    Customer *p = Customs;
    for(int i = 0;i < num1-1;i++)
    {
        scanf("%ld %d",&p->SeriesCount,&p->RequestSeries);
        p->TargetedSeries = MAX;
        p->next = (Customer *)malloc(sizeof(Customer));
        p = p->next;
    }
    scanf("%ld %d",&p->SeriesCount,&p->RequestSeries);
    p->TargetedSeries = MAX;
    p->next = NULL;
    return;
}

void CreateBookList(Book *BookList,int num2)
{
    Book *p = BookList;
    for(int i = 0;i < num2-1;i++)
    {
        scanf("%ld",&p->BookSeries);
        p->next = (Book *)malloc(sizeof(Book));
        p = p->next;
    }
    scanf("%ld",&p->BookSeries);
    p->next = NULL;
    return;
}

int main()
{
    int num1,num2;
    scanf("%d %d",&num2,&num1);
    Customer *Customs = (Customer *)malloc(sizeof(Customer));
    Book *BookList = (Book *)malloc(sizeof(Book));
    CreateBookList(BookList,num2);
    CreateCustomerList(Customs,num1);
    for(Customer *p = Customs;p != NULL;p = p->next)
    {
        SearchBook(BookList,p);
        printf("%ld\n",p->TargetedSeries);
    }
    return 0;
}