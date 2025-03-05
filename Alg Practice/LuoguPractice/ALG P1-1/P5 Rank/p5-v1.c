/*现给一份名单，包括姓名，职位，贡献，等级。前三个人是帮主和两位副帮主，他们不参与排序。对于剩下的人，按照贡献值排序，贡献值相同的人保持原来的先后顺序不变
之后从第四个人起，按照两位HuFa，四位ZhangLao，七位TangZhu，二十五名JingYing，余下的人是BangZhong的顺序给他们重新分配rank
如果人员不够，就按照顺序分配到最后一人
之后再将这些人按照职位（rank）优先，其次等级的顺序排序，等级相同的，原来靠前的现在也要靠前
最后打印输出所有人的姓名，职位和等级*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[30];
    char position[30];
    int contribution;
    int rank;
} Person;

int cmp(const void *a, const void *b) {
    Person *pa = (Person *)a;
    Person *pb = (Person *)b;
    if (pa->contribution != pb->contribution) {
        return pb->contribution - pa->contribution;
    } else if (pa->rank != pb->rank) {
        return pa->rank - pb->rank;
    } else {
        return strcmp(pa->name, pb->name);
    }
}

int main() {
    Person person[MAX];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%s%d%d", person[i].name, person[i].position, &person[i].contribution, &person[i].rank);
    }
    qsort(person + 3, n - 3, sizeof(Person), cmp);
    int rank = 1;
    for (int i = 3; i < n; i++) {
        if (rank == 1) {
            strcpy(person[i].position, "HuFa");
        } else if (rank <= 3) {
            strcpy(person[i].position, "ZhangLao");
        } else if (rank <= 7) {
            strcpy(person[i].position, "TangZhu");
        } else if (rank <= 25) {
            strcpy(person[i].position, "JingYing");
        } else {
            strcpy(person[i].position, "BangZhong");
        }
        person[i].rank = rank;
        rank++;
        if (rank > 25) {
            rank = 25;
        }
    }
    qsort(person, n, sizeof(Person), cmp);
    for (int i = 0; i < n; i++) {
        printf("%s %s %d\n", person[i].name, person[i].position, person[i].rank);
    }
    return 0;
}

