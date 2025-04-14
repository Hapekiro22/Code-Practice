#include <stdio.h>
#include <omp.h>

int main()
{
    int k = 100;

    #pragma omp parallel for reduction(+:k)
        for(int i = 0;i < 10;i++)
        {
            k += i;
        }

    printf("Added k = %d\n",k);

    k = 100;

    #pragma omp parallel for reduction(*:k)
        for(int i = 1;i < 10;i++)
        {
            k *= i;
        }

    printf("Multiplied k = %d\n",k);


    //多变量
    int sum = 0,product = 1;
    #pragma omp parallel for reduction(+:sum) reduction(*:product)
        for(int i = 1;i < 10;i++)
        {
            sum += i;
            product *= i;
        }

    printf("Sum = %d, Product = %d\n",sum,product);

    return 0;
}

//reduction指定了k是reduction的，每个线程都有自己的k，
//k副本会获得一个初始值，然后每个线程都会对自己的k副本进行运算
//最后所有线程的k副本会被合并到一个k中
//要注意在for循环中的语句要遵守reduction的声明

//这里reduction变相的实现了firstprivate和lastprivate的功能

//不过过多的线程会大大增加reduction初始化的开销