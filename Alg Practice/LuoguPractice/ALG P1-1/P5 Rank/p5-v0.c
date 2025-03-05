#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct member
{
    int series;
    long lvl,contrib;
    char rank[30];
    char name[30];
} member;

int compareContrib(member *a, member *b) {

    // 等级相同比较贡献
    if (a->contrib != b->contrib)
        return (a->contrib > b->contrib) ? 1 : -1;
    
    // 都相同按原始顺序
    return (a->series < b->series) ? -1 : 1;
}

int compareLvl(member *a, member *b) {

    // 等级相同比较贡献
    if (a->lvl != b->lvl)
        return (a->lvl > b->lvl) ? 1 : -1;
    
    // 都相同按原始顺序
    return (a->series < b->series) ? -1 : 1;
}

void merge(member *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // 创建临时数组
    member *L = (member *)malloc(n1 * sizeof(member));
    member *R = (member *)malloc(n2 * sizeof(member));
    
    // 复制数据到临时数组
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // 合并临时数组
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (compareContrib(&L[i], &R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // 复制剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergelvl(member *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // 创建临时数组
    member *L = (member *)malloc(n1 * sizeof(member));
    member *R = (member *)malloc(n2 * sizeof(member));
    
    // 复制数据到临时数组
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // 合并临时数组
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (compareLvl(&L[i], &R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // 复制剩余元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(member *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSortlvl(member *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortlvl(arr, left, mid);
        mergeSortlvl(arr, mid + 1, right);
        mergelvl(arr, left, mid, right);
    }
}

void printList(member *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %s %ld %ld\n", arr[i].name, arr[i].rank, arr[i].contrib, arr[i].lvl);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    member *members = (member *)malloc(n * sizeof(member));
    for(int i = 0;i < n;i++)
    {
        scanf("%s %s %ld %ld",members[i].name,members[i].rank,&members[i].contrib,&members[i].lvl);
        members[i].series = i;
    }
    mergeSort(members,0,n-1);
    printList(members,n);

    if(n > 3)
    for(int i = 3;i < n;i++)
    {
        char temp[30];
        if(i == 3) strcpy(temp,"HuFa");
        if(i == 5) strcpy(temp,"ZhangLao");
        if(i == 9) strcpy(temp,"TangZhu");
        if(i == 16) strcpy(temp,"JingYing");
        if(i == 41) strcpy(temp,"BangZhong");

        if(i >= 3 && i < 5) strcpy(members[i].rank,temp);
        if(i >= 5 && i < 9) strcpy(members[i].rank,"HuFa");
        if(i >= 9 && i < 16) strcpy(members[i].rank,"ZhangLao");
        if(i >= 16 && i < 41) strcpy(members[i].rank,"TangZhu");
        if(i >= 41) strcpy(members[i].rank,"JingYing");

    }

    printList(members,n);

    mergeSortlvl(members,3,4);
    mergeSortlvl(members,5,8);
    mergeSortlvl(members,9,15);
    mergeSortlvl(members,16,40);
    mergeSortlvl(members,41,n-1);

    for(int i = 0;i < n;i++)
    {
        printf("%s %s %ld\n",members[i].name,members[i].rank,members[i].lvl);
    }

    free(members);
    return 0;




}