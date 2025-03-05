#include <iostream>
#include <sys/time.h>
#include <immintrin.h>
#include <thread>
#include <cstdint>
#include <vector>
#include <mutex>
#include <algorithm>

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

int AVX_sum_array(int *arr, int len)
{
    // 确保数据对齐
    if ((uintptr_t)arr % 32 != 0) {
        std::cerr << "数据未对齐" << std::endl;
        return sum_array(arr, len); // 回退到普通版本
    }
    
    // 使用适量线程，基于CPU核心数
    const int num_threads = std::min(8, (int)std::thread::hardware_concurrency());
    std::vector<std::thread> threads;
    
    // 使用一个互斥锁保护共享变量
    std::mutex sum_mutex;
    __m256i total_sum = _mm256_setzero_si256();
    
    // 每线程处理部分数据
    int chunk_size = (len / 8) / num_threads;
    if (chunk_size == 0) chunk_size = 1;
    
    for (int t = 0; t < num_threads; t++) {
        int start = t * chunk_size * 8;
        int end = (t == num_threads - 1) ? (len / 8) * 8 : (t + 1) * chunk_size * 8;
        if (end > len) end = len - (len % 8);
        
        threads.push_back(std::thread([arr, start, end, &sum_mutex, &total_sum]() {
            __m256i local_sum = _mm256_setzero_si256();
            
            for (int i = start; i < end; i += 8) {
                __m256i v = _mm256_load_si256((__m256i*)(arr + i));
                local_sum = _mm256_add_epi32(local_sum, v);
            }
            
            // 线程安全地更新总和
            std::lock_guard<std::mutex> lock(sum_mutex);
            total_sum = _mm256_add_epi32(total_sum, local_sum);
        }));
    }
    
    // 等待所有线程完成
    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }
    
    // 正确提取向量元素和
    alignas(32) int result[8];
    _mm256_store_si256((__m256i*)result, total_sum);
    
    int final_sum = 0;
    for (int i = 0; i < 8; i++) {
        final_sum += result[i];
    }
    
    // 处理剩余元素
    int remaining_start = (len / 8) * 8;
    for (int i = remaining_start; i < len; i++) {
        final_sum += arr[i];
    }
    
    return final_sum;
}

int main()
{
    const int k = 512*512;
    const int loop = 512;

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