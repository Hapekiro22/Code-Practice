#include <iostream>
#include <omp.h>
#include <stdio.h>

int main()
{

    #pragma omp parallel for
    for(int i = 0;i < 10;i++)
    {
        printf("i = %d\n",i);
    }

    return 0;
}

//i会被分配给不同的线程，每个线程都会输出i的值
//编译器会在进入并行区时，提前将i的值拷贝到线程的私有内存中
//这样每个线程都有自己的i，不会出现数据竞争