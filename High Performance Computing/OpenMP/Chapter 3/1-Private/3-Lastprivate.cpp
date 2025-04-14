#include <stdio.h>
#include <omp.h>

int main()
{
    int k = 100;

    #pragma omp parallel for firstprivate(k),lastprivate(k)
        for(int i = 0;i < 10;i++)
        {
            printf("k = %d\n",k += i);
        }

    printf("Final k = %d\n",k);

    return 0;
}

//lastprivate(k)指定了k是lastprivate的，每个线程都有自己的k，
//但是最后输出的k是最后一个线程的k
//OpenMP会保证程序逻辑顺序上的最后一个k继承到并行区域外
//在使用for时，最后一个循环的k会被继承到并行区域外
//在使用sections时，最后一个section的k会被继承到并行区域外

//注意这里k是private的所以自增运算不会在内部互相影响

//这里也展示了firstprivate和lastprivate可以同时使用
//firstprivate会继承并行区域外的值
//lastprivate会输出最后一个线程的值