#include <iostream>
#include <sys/time.h>
#include <immintrin.h>
#include <thread>
#include <cstdint>

#define LEN (512*512)

using namespace std;

int sum_array(int *arr, int len) {
    int sum = 0;
    for(int i = 0; i < len; ++i) {
      sum += arr[i];
    }
    return sum;
  }
  
int dot_product(int *a, int *b, int len) {
    int sum = 0;
    for(int i = 0; i < len; ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}

int AVX_sum_array(int *arr,int len)
{
    // 确保数据对齐
    if ((uintptr_t)arr % 32 != 0) {
        std::cerr << "数据未对齐" << std::endl;
        return sum_array(arr, len); // 回退到普通版本
    }

    int offset = 8;
    __m256i v1;
    __m256i sum = _mm256_setzero_si256();

    int ret = 0;

    for(int i = 0;i < len/8;i++)
    {
        thread t([i,&offset,&v1,&sum,arr]{
            v1 = _mm256_load_si256((__m256i *)(arr + offset * i));
            sum = _mm256_add_epi32(sum,v1);
        });
        t.detach();
    }

    sum = _mm256_hadd_epi32(sum,sum);
    ret += sum[0];
    ret += sum[4];

    return ret;
}

int main()
{
    const int k = 512;
    const int loop = 1;

    struct timeval start;
    struct timeval end;

    alignas(32) int *input1 = (int *)malloc(k * sizeof(int));

    for(int i = 0;i < k;i++)
    {
        input1[i] = i;
    }

    gettimeofday(&start, nullptr);

    for(int j = 0;j < loop;j++)
    {
        sum_array(input1,k);
    }

    gettimeofday(&end, nullptr);

    cout << "sum_array time: " << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << endl;

    gettimeofday(&start, nullptr);

    for(int j = 0;j < loop;j++)
    {
        AVX_sum_array(input1,k);
    }

    gettimeofday(&end, nullptr);

    cout << "AVX_sum_array time: " << (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec) << " us" << endl;

    return 0;

}