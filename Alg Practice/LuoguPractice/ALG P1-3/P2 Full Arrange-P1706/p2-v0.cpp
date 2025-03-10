#include <stdio.h>
#include <iostream>
#define MAX 9

using namespace std;

int count[MAX] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
int record[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void FullArrange(int n,int rest)
{

    for(int i = 0;i < n;i++)
    {
        if(*(count + i) > 0)
        {
            (*(count + i)) --;
            record[n - rest] = i + 1;
            
            if(rest == 1)
            {
                for(int j = 0;j < n;j++)
                    printf("%5d",record[j]);
                printf("\n");
                (*(count + i)) ++;
                return;
            }

            FullArrange(n,rest - 1);
            (*(count + i)) ++;
            record[n - rest] = 0;
        }
    }

    return;
}


int main()
{
    int n,rest;
    cin >> n;
    rest = n;
    FullArrange(n,rest);
    return 0;
}