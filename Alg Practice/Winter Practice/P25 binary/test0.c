#include <stdio.h>

long nearest_multiple_of_500(long x) {
    if (x >= 0) {
        return ((x + 499) / 500) * 500;
    } else {
        return ((x + 499) / 500) * 500;
    }
}

int main() {
    long x = -3123;
    long result = nearest_multiple_of_500(x);

    printf("The smallest multiple of 500 that is not less than %ld is %ld\n", x, result);

    return 0;
}