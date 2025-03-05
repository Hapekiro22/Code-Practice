#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50
#define T0 "BangZhu"
#define T1 "FuBangZhu"
#define T2 "HuFa"
#define T3 "ZhangLao"
#define T4 "TangZhu"
#define T5 "JingYing"
#define T6 "BangZhong"

typedef struct player
{
    char name[LEN];
    char rank[LEN];
    long lvl, ctrib;
    int series;
} player;

void merge(player arr[], int l, int m, int r, int (*cmp)(const void *, const void *))
{
    int n1 = m - l + 1;
    int n2 = r - m;
    player *L = (player *)malloc(n1 * sizeof(player));
    player *R = (player *)malloc(n2 * sizeof(player));
    if (L == NULL || R == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (cmp(&L[i], &R[j]) <= 0)
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    //free(L);
    //free(R);
}

void mergeSort(player arr[], int l, int r, int (*cmp)(const void *, const void *))
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, cmp);
        mergeSort(arr, m + 1, r, cmp);
        merge(arr, l, m, r, cmp);
    }
}

int compareContrib(const void *a, const void *b)
{
    player *playerA = (player *)a;
    player *playerB = (player *)b;
    return playerB->ctrib - playerA->ctrib;
}

int compareLvl(const void *a, const void *b)
{
    player *playerA = (player *)a;
    player *playerB = (player *)b;
    return playerB->lvl - playerA->lvl;
}

void printList(player *p, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s %s %ld %ld\n", p[i].name, p[i].rank, p[i].ctrib, p[i].lvl);
    }
    printf("\n");
}

int main()
{
    //FILE *fp = fopen("test1.in", "r");
    long n;
    scanf("%ld", &n);
    player *p = (player *)malloc(n * sizeof(player));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %ld %ld", p[i].name, p[i].rank, &p[i].ctrib, &p[i].lvl);
        p[i].series = i;
        if (strcmp(p[i].rank, T0) == 0)
        {
            player temp = p[i];
            p[i] = p[0];
            p[0] = temp;
        }
        if (strcmp(p[i].rank, T1) == 0)
        {
            player temp = p[i];
            p[i] = p[count];
            p[count++] = temp;
        }
    }

    player *p0 = p;
    if(n > 3)
        mergeSort(p0, 3, n - 1, compareContrib);
    //printList(p0, n);

    for (int i = 3; i < n; i++)
    {
        if (i >= 3 && i <= 4)
        {
            strcpy(p[i].rank, T2);
        }
        else if (i >= 5 && i <= 8)
        {
            strcpy(p[i].rank, T3);
        }
        else if (i >= 9 && i <= 15)
        {
            strcpy(p[i].rank, T4);
        }
        else if (i >= 16 && i <= 40)
        {
            strcpy(p[i].rank, T5);
        }
        else
        {
            strcpy(p[i].rank, T6);
        }
    }

    mergeSort(p0 + 3,0,1,compareLvl);
    mergeSort(p0 + 5,0,3,compareLvl);
    mergeSort(p0 + 9,0,6,compareLvl);
    mergeSort(p0 + 16,0,24,compareLvl);
    mergeSort(p0 + 41,0,n-42,compareLvl);

    if(n > 3)
    for(int i = 3;i <= 4;i++)
    {
        for(int j = i;j <= 4;j++)
        {
            if(p[j].series > p[i].series && p[j].lvl == p[i].lvl)
            {
                player temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    if(n > 5)
    for(int i = 5;i <= 8;i++)
    {
        for(int j = i;j <= 8;j++)
        {
            if(p[j].series > p[i].series && p[j].lvl == p[i].lvl)
            {
                player temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    if(n > 9)
    for(int i = 9;i <= 15;i++)
    {
        for(int j = i;j <= 15;j++)
        {
            if(p[j].series > p[i].series && p[j].lvl == p[i].lvl)
            {
                player temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    if(n > 16)
    for(int i = 16;i <= 40;i++)
    {
        for(int j = i;j <= 40;j++)
        {
            if(p[j].series > p[i].series && p[j].lvl == p[i].lvl)
            {
                player temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    if(n > 41)
    for(int i = 41;i < n;i++)
    {
        for(int j = i;j < n;j++)
        {
            if(p[j].series > p[i].series && p[j].lvl == p[i].lvl)
            {
                player temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    if (p[1].lvl < p[2].lvl)
    {
        player temp = p[1];
        p[1] = p[2];
        p[2] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s %s %ld\n", p[i].name, p[i].rank, p[i].lvl);
    }

    //free(p);
    return 0;
}