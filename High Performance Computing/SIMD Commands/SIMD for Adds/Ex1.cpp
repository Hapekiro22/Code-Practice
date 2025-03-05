#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#include <iostream>
#include <sys/time.h>


//Unoptimized code
double addCommand(double *data,int count)
{
    double result = 0;

    for (int i = 0 ; i < count; i++) {
        result += data[i];
    }

    return result;
}

//Optimized code
double OptimizedAddCommand(double *data,int count)
{
    int offset = 0;

    __m256d v1;
    __m256d sum = _mm256_setzero_pd();

    double ret = 0;

    for(int i = 0;i < count / 4;i++)
    {
        v1 = _mm256_load_pd(data + offset);
        sum = _mm256_add_pd(sum,v1);
        offset += 4;                    //偏移量，每次加载data中的4个浮点数
    }

    sum = _mm256_hadd_pd(sum,sum);      //再将所有部分和相加

    ret += sum[0];
    ret += sum[2];

    return ret;
}

int main() {

    struct  timeval   start;
    struct  timeval   end;


    const int k = 512 * 512;

    const int loop = 1;

    alignas(32) double *input1 = (double *)malloc(k * sizeof(double));

    for (int i = 0; i < k; i++) {
        input1[i] = i;
    }

    gettimeofday(&start, nullptr);

    for (int j = 0; j < loop; j++) {
        addCommand(input1, k);
    }

    gettimeofday(&end, nullptr);

    printf("tv_sec:%ld\n",end.tv_sec - start.tv_sec);
    printf("tv_usec:%d\n", end.tv_usec - start.tv_usec);

    std::cout << " ======================= " << std::endl;

    gettimeofday(&start, nullptr);

    for (int j = 0; j < loop; j++) {
        OptimizedAddCommand(input1, k);
    }

    gettimeofday(&end, nullptr);

    printf("tv_sec:%ld\n",end.tv_sec - start.tv_sec);
    printf("tv_usec:%d\n", end.tv_usec - start.tv_usec);

    return 0;
}