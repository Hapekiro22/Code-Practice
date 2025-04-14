#include <stdio.h>
#include <omp.h>

int main()
{
    int k = 100;

    #pragma omp parallel for firstprivate(k)
        for(int i = 0;i < 10;i++)
        {
            printf("k = %d\n",k += i);
        }

    printf("k = %d\n",k);

    return 0;
}

//firstprivate(k)指定了k是firstprivate的，每个线程都有自己的k，
//但是k会继承并行区域外的值

//注意这里k是private的所以自增运算不会在内部互相影响