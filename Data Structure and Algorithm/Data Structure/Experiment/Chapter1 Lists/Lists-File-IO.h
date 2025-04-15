#include "Def.h"
#include "Lists.h"

void ListWrite(SqList *L, char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr,"Error opening file!\n");
        return;
    }

    fprintf(fp, "%d\n", L -> length);
    for (int i = 0; i < L -> length; i++) {
        fprintf(fp, "%d ", L -> elem[i]);
    }
    fclose(fp);
}

void ListRead(SqList *L, char *filename)
{
    if(L -> elem != NULL)
    {
        fprintf(stderr, "Error: List is not NULL\n");
        return;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr,"Error opening file!\n");
        return;
    }

    fscanf(fp, "%d", &L->length);
    L->listsize = LIST_INIT_SIZE * (L ->length / LIST_INIT_SIZE + 1);
    L->elem = (ElemType *)malloc(sizeof(ElemType) * L->length);
    for (int i = 0; i < L->length; i++) {
        fscanf(fp, "%d", &L->elem[i]);
    }
    fclose(fp);
}