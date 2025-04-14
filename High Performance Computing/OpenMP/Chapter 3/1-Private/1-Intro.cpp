#include <stdio.h>
#include <omp.h>

int main()
{
    int k = 10043;

    #pragma omp parallel for private(k)
        for(k = 0;k < 10;k++)
        {
            printf("k = %d\n",k);
        }

    printf("k = %d\n",k);

    return 0;
}

//private(k)指定了k是私有的，每个线程都有自己的k
//k不会继承并行区域外的值

/*private 子句用亍将一个戒多个变量声明成线程私有的变量，
变量声明成私有变量后，指定每个线程都有它自己的变量私有副本，其他线程无法访问私有副本。
即使在并行区域外有同名的共享变量，共享变量在并行区域内不起任何作用，
并且并行区域内操作不会影响到外面的共享变量。*/

//比如这个例子中，k是私有的，每个线程都有自己的k，所以最后输出的k是10043
//如果不声明private(k)，则最后输出的k是10