#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 10000

void BigSum(char *a, char *b, char *result) {
    int Anum[MAX_DIGITS] = {0}, Bnum[MAX_DIGITS] = {0}, Res[MAX_DIGITS + 1] = {0};
    int lenA = strlen(a), lenB = strlen(b);
    int i, carry = 0;

    // 将字符串转换为数字数组，低位在前
    for (i = 0; i < lenA; i++) {
        Anum[i] = a[lenA - 1 - i] - '0';
    }
    for (i = 0; i < lenB; i++) {
        Bnum[i] = b[lenB - 1 - i] - '0';
    }

    int maxLen = lenA > lenB ? lenA : lenB;

    // 进行大数加法
    for (i = 0; i < maxLen; i++) {
        int sum = Anum[i] + Bnum[i] + carry;
        Res[i] = sum % 10;
        carry = sum / 10;
    }
    if (carry) {
        Res[maxLen] = carry;
        maxLen++;
    }

    // 将结果转换为字符串
    for (i = 0; i < maxLen; i++) {
        result[i] = Res[maxLen - 1 - i] + '0';
    }
    result[maxLen] = '\0';
}

void BigMul(char *a, char *b, char *result) {
    int Anum[MAX_DIGITS] = {0}, Bnum[MAX_DIGITS] = {0}, Res[2 * MAX_DIGITS] = {0};
    int lenA = strlen(a), lenB = strlen(b);
    int i, j;

    // 将字符串转换为数字数组，低位在前
    for (i = 0; i < lenA; i++) {
        Anum[i] = a[lenA - 1 - i] - '0';
    }
    for (i = 0; i < lenB; i++) {
        Bnum[i] = b[lenB - 1 - i] - '0';
    }

    // 进行大数乘法
    for (i = 0; i < lenA; i++) {
        for (j = 0; j < lenB; j++) {
            Res[i + j] += Anum[i] * Bnum[j];
            if (Res[i + j] >= 10) {
                Res[i + j + 1] += Res[i + j] / 10;
                Res[i + j] %= 10;
            }
        }
    }

    int maxLen = lenA + lenB;
    while (maxLen > 1 && Res[maxLen - 1] == 0) {
        maxLen--;
    }

    // 将结果转换为字符串
    for (i = 0; i < maxLen; i++) {
        result[i] = Res[maxLen - 1 - i] + '0';
    }
    result[maxLen] = '\0';
}

int main() {
    char a[MAX_DIGITS], b[MAX_DIGITS], result[2 * MAX_DIGITS];

    printf("输入两个大数进行加法:\n");
    scanf("%s %s", a, b);
    BigSum(a, b, result);
    printf("加法结果: %s\n", result);

    printf("输入两个大数进行乘法:\n");
    scanf("%s %s", a, b);
    BigMul(a, b, result);
    printf("乘法结果: %s\n", result);

    return 0;
}

