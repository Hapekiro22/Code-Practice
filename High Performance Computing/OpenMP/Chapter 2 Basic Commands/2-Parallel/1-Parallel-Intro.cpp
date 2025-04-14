#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(8)
    {
        printf("Hello World, Thread id = %d\n",omp_get_thread_num());
    }

    return 0;
}


//parallel指令会将其下面的代码块并行化
//num_threads(8)指定了并行区域中的线程数
//omp_get_thread_num()返回当前线程的id
//每个线程都会输出自己的id


//如果不指定num_threads(8)，则默认使用所有的线程