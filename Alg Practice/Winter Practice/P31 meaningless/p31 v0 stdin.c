#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LIMIT 100000

long primeList[LIMIT] = {0};

int is_Prime(long n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void sieve_of_eratosthenes(int limit)
{
    int isPrime[LIMIT + 1];
    for(int i = 0;i <= LIMIT;i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;

    for(int i = 2;i <= sqrt(LIMIT);i++)
    {
        if(is_Prime(i))
        {
            for(int j = i * i;j <= LIMIT;j += i)
                isPrime[j] = 0;
        }
    }

    int index = 0;
    for(int i = 0;i <= LIMIT;i++)
    {
        if(isPrime[i])
        {
            primeList[index++] = i;
            //printf("%d ", i);
        }
    }

}

int main()
{
    //FILE *fp = fopen("meaningless/meaningless3.in", "r");
    sieve_of_eratosthenes(LIMIT);
    int q;
    scanf("%d", &q);
    long **arr = (long **)malloc(q * sizeof(long *));
    for (int i = 0; i < q; i++) {
        arr[i] = (long *)malloc(2 * sizeof(long));
        scanf("%ld %ld", &arr[i][0], &arr[i][1]);
    }
    //fclose(fp);

    for(int i = 0;i < q;i++)
    {
        long newnum = 1;
        int lowest = arr[i][1];
        for(int j = 0;primeList[j] <= sqrt(arr[i][0]);j++)
        {
            long temp = arr[i][0];
            int count = 0;
            //printf("temp: %ld\n", temp);
            //printf("primeList[j]: %ld\n", primeList[j]);
            while(!(temp % primeList[j]))
            {
                temp /= primeList[j];
                count++;
            }
            if(count >= lowest)
                newnum *= pow(primeList[j],count); 
        }
        printf("%ld\n",newnum);
    }

    free(arr);
    return 0;
}