#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    alignas(32) double input1[4] = {1.0, 2.0, 3.0, 4.0};
    alignas(32) double input2[4] = {5.0, 6.0, 7.0, 8.0};
    alignas(32) double result[4] = {0.0, 0.0, 0.0, 0.0};

    __m256d a = _mm256_load_pd(input1);
    __m256d b = _mm256_load_pd(input2);
    
    __m256d c = _mm256_add_pd(a, b);
    _mm256_store_pd(result, c);

    for (int i = 0; i < 4; i++)
    {
        printf("%f ", result[i]);
    }

    return 0;
}