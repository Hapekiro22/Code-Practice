#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MEM_LEN 32
#define READ 0
#define WRITE 1
#define AVAIL -1

#define DEBUG 1

using namespace std;

struct Cache
{
    long long tag;
    bool operation;
    Cache *next, *prev;
};

typedef Cache *cacheList;
typedef Cache memory;
typedef Cache cache;

inline int getCacheIndex(int MemoryAddress,int cacheSize,int groupSize);
inline cacheList *initCacheList(int cacheSize,int groupSize);
inline cacheList **initQueueInfo(int groupSize,cacheList *cacheGroup);
cache *isCacheHit(int MemoryAddress,int cacheSize,cacheList list);
cache *getAvailCache(cacheList list);
void LRU(cache *hit,cache *head,cache *tail);


int main()
{
    FILE *fin = fopen("evaldata/p3-1.in", "r");
    FILE *fout = fopen("evaldata/p3-1.out", "w");

    int cacheSize, groupSize, commandCount;
    fscanf(fin, "%d %d %d", &cacheSize, &groupSize, &commandCount);

    cacheList *cacheGroup = initCacheList(cacheSize, groupSize);
    cacheList **queueInfo = initQueueInfo(groupSize, cacheGroup);
    
    for(int i = 0;i < commandCount;i++)
    {
        #ifdef DEBUG
        cout << "Command " << i << endl;
        #endif

        int MemoryAddress,operation;
        fscanf(fin, "%d %d", &MemoryAddress, &operation);
        int index = getCacheIndex(MemoryAddress, cacheSize, groupSize);
        cache *hit = isCacheHit(MemoryAddress, cacheSize, cacheGroup[index]);
        cache *head = *(*(queueInfo + index) + 0);
        cache *tail = *(*(queueInfo + index) + 1);

        #ifdef DEBUG
        cout << "Memory Address: " << MemoryAddress << endl << " Operation: " << operation << endl << " Index: " << index << endl;
        #endif

        if(hit != NULL)
        {
            if(operation == READ)
            {
                LRU(hit,head,tail);
                continue;
            }
            else if(operation == WRITE)
            {
                LRU(hit,head,tail);
                hit -> operation = WRITE;
                fprintf(fout,"%d %d\n",WRITE,MemoryAddress);
                continue;
            }
        }

        else if(hit == NULL)
        {
            cache *available = getAvailCache(cacheGroup[index]);
            if(available != NULL)
            {
                available -> tag = MemoryAddress;
                available -> operation = operation;
                LRU(available,head,tail);           
                fprintf(fout,"%d %d\n",operation,MemoryAddress);
            }

            else if(available == NULL)
            {
                cache *victim = tail;
                fprintf(fout,"%d %d\n",WRITE,victim -> tag);
                victim -> tag = MemoryAddress;
                victim -> operation = operation;
                LRU(victim,head,tail);         

                tail = tail -> prev;
                tail -> next = NULL;          
                fprintf(fout,"%d %d\n",READ,MemoryAddress);
            }
        }

        queueInfo[index][0] = head;
        queueInfo[index][1] = tail;

    }

    fclose(fin);
    fclose(fout);
    return 0;
    
}

inline int getCacheIndex(int MemoryAddress,int cacheSize,int groupSize)
{
    return ((MemoryAddress - MemoryAddress % cacheSize) / cacheSize) % groupSize;
}

inline cacheList *initCacheList(int cacheSize,int groupSize)
{
    cacheList *cacheGroup = new cacheList[groupSize];
    for(int i = 0;i < groupSize;i++)
    {
        cacheGroup[i] = new Cache[cacheSize];
        cacheGroup[i][0].tag = -1;
        cacheGroup[i][0].operation = READ;
        cacheGroup[i][0].next = cacheGroup[i] + 1;
        cacheGroup[i][0].prev = NULL;
        for(int j = 1;j < cacheSize - 1;j++)
        {
            cacheGroup[i][j].tag = AVAIL;
            cacheGroup[i][j].operation = READ;
            cacheGroup[i][j].next = cacheGroup[i] + j + 1;
            cacheGroup[i][j].prev = cacheGroup[i] + j - 1;
        }
        cacheGroup[i][cacheSize - 1].tag = -1;
        cacheGroup[i][cacheSize - 1].operation = READ;
        cacheGroup[i][cacheSize - 1].next = NULL;
        cacheGroup[i][cacheSize - 1].prev = cacheGroup[i] + cacheSize - 2;
    }

    return cacheGroup;
}

inline cacheList **initQueueInfo(int groupSize,cacheList *cacheGroup)
{
    cacheList **queueInfo = new cacheList*[groupSize];
    for(int i = 0;i < groupSize;i++)
    {
        queueInfo[i] = new cache*[2];
        queueInfo[i][0] = cacheGroup[i];
        cache *tail = cacheGroup[i];
        while(tail -> next != NULL)
        {
            tail = tail -> next;
        }
        queueInfo[i][1] = tail;
        
    }

    return queueInfo;
}

cache *isCacheHit(int MemoryAddress,int cacheSize,cacheList list)
{
    cache *current = list;
    while(current -> next != NULL)
    {
        if(current -> tag == MemoryAddress)
        {
            return current;
        }
        current = current -> next;
    }

    return NULL;
}

cache *getAvailCache(cacheList list)
{
    cache *current = list;
    while(current -> next != NULL)
    {
        if(current -> tag == AVAIL)
        {
            return current;
        }
        current = current -> next;
    }

    return NULL;
}
