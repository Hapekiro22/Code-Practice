#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOWEST -50000

using namespace std;

int main()
{
    FILE *fin = fopen("evaldata/p2-1.in", "r");
    FILE *fout = fopen("evaldata/p2-1.out", "w");
    int n;
    fscanf(fin, "%d", &n);
    int *cost = (int *)malloc((n + 1)* sizeof(int));
    int *supply = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n + 1; i++)
    {
        fscanf(fin, "%d", &cost[i]);
    }

    for (int i = 1; i < n + 1; i++)
    {
        fscanf(fin, "%d", &supply[i]);
    }
    supply[0] = 0;

    int *w = (int *)malloc((n + 1)* sizeof(int));
    for(int i = 0; i < n + 1; i++)
        w[i] = 0;
    w[0] = cost[0] - supply[0];

    int maxw = w[0],maxwindex = 0;
    for(int i = 1;i < n + 1;i++)
    {
        w[i] = w[i - 1] + cost[i] - supply[i];
        //cout << w[i] << " ";
        maxw = maxw > w[i] ? maxw : w[i];
        maxwindex = maxw > w[i] ? maxwindex : i;
    }
    
    //cout << maxw << " " << maxwindex << endl;

    for(int i = 1;i <= maxwindex;i++)
    {
        fprintf(fout,"%d\n",maxw + supply[i]);
    }

    int temp = maxw;
    for(int i = maxwindex + 1;i < n + 1;i++)
    {
        for(int j = i;j < n + 1;j++)
        {
            if(w[j] + supply[i] > maxw)
            {
                maxw = w[j] + supply[i];
            }
        }
        fprintf(fout,"%d\n",maxw);
        maxw = temp;
    }

    fclose(fin);
    fclose(fout);
    free(cost);
    free(supply);
    free(w);
    return 0;
    
}