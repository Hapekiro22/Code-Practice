#include <iostream>
#include <random>
#include <stdio.h>
#define UPPER_N 20000
#define UPPER_COST 1000


using namespace std;

int main()
{
    FILE *fout = fopen("p2-1.in", "w");
    srand(time(NULL));
    int n = rand() % UPPER_N + 1;
    fprintf(fout, "%d\n", n);

    // Generate costs
    for (int i = 0; i < n + 1; i++)
    {
        fprintf(fout, "%d ", rand() % UPPER_COST);
    }

    cout << endl;
    // Generate supplies
    for(int i = 1; i < n + 1; i++)
    {
        fprintf(fout, "%d ", rand() % UPPER_COST);
    }

    fclose(fout);
    return 0;
}