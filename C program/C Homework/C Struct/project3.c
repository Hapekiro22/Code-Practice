#include<stdio.h>
#include<string.h>

struct web  /*  设计表示网址的结构  */
{
    /**********  Begin  **********/
    char full_name[200];
    char url[200];
    char name[200];
	/**********   End   **********/
};

void sort(struct web webs[],int n);
#define N  4      /*  网址表大小  */

int main()
{
	/**********  Begin  **********/
    struct web webs[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%s %s %s", webs[i].name, webs[i].full_name, webs[i].url);
    }
    sort(webs,N);
    char enteredname[200];
    scanf("%s", enteredname);
    for(int i = 0; i < N; i++)
    {
        printf("%s ",webs[i].name);
        printf("%s ",webs[i].full_name);
        printf("%s\n",webs[i].url);
    }
    int flag = 0;
    for(int i = 0; i < N; i++)
    {
        if(strcmp(webs[i].name, enteredname) == 0)
        {
            printf("%s\n",webs[i].url);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("未找到搜寻的网址\n");
    }

	/**********   End   **********/
	return 0; 
}

void sort(struct web webs[],int n)
{
	/**********  Begin  **********/
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(webs[i].name, webs[j].name) > 0)
            {
                struct web temp = webs[i];
                webs[i] = webs[j];
                webs[j] = temp;
            }
        }
    }

	/**********   End   **********/
}