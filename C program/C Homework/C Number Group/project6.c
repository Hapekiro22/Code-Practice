//判断一个字符串是否是回文的（如123321）
#include<stdio.h>
#include<string.h>

#define SIZE 100

int IsPalindrome(char *arr,int len);

int main()
{
    char arr[SIZE];
    scanf("%s",arr);
    int len = strlen(arr);

    if(IsPalindrome(arr,len))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}

int IsPalindrome(char *arr,int len)
{
    int count = 0;
    while(count<(len-1-count))
    {
        if(arr[count]!=arr[len-count-1])
        {
            return 0;
        }
        else count++;
    }

    return 1;
}
