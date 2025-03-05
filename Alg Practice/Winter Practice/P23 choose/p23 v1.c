#include <stdio.h>
#include <stdlib.h>

int count = 0;

int isPrime(int num)
{
    if(num <= 1)
        return 0;
    if(num <= 3)
        return 1;
    if(num % 2 == 0 || num % 3 == 0)
        return 0;
    for(int i = 5;i * i <= num;i += 6)
    {
        if(num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// 递归函数，用于计算所有任意 k 个数的组合的和
void calculateSums(long *arr, int n, int k, int start, long currentSum, int currentCount) {
    // 如果已经选择了 k 个数，则输出当前和
    if (currentCount == k) {
        //printf("%ld\n", currentSum);
        if(isPrime(currentSum))
            count++;
        return;
    }

    // 递归选择剩余的数
    for (int i = start; i < n; i++) {
        calculateSums(arr, n, k, i + 1, currentSum + arr[i], currentCount + 1);
    }
}

int main() {
    int n, k;
    //printf("Enter the number of elements (n) and the number of elements to sum (k): ");
    scanf("%d %d", &n, &k);

    long *arr = (long *)malloc(n * sizeof(long));
    if (arr == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

   // printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    //printf("The sums of all combinations of %d elements are:\n", k);
    calculateSums(arr, n, k, 0, 0, 0);
    printf("%d\n", count);

    free(arr);
    return 0;
}