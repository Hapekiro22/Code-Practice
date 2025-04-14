#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 0;
    #pragma omp parallel for
        for(int i = 0;i < 10;i++)
        {
            printf("i = %d\n",i);
        }

    return 0;
}



//如果只用for并不声明parallel，那么只有一个线程会执行for循环
//如果用了parallel，那么for循环会被分配给不同的线程

//如果使用parallel for，则for循环会被分配给不同的线程
//在进入并行区时，编译器会提前将i的值拷贝到线程的私有内存中
//这样每个线程都有自己的i，不会出现数据竞争
//每个线程都会输出i的值

//注意这里for中小括号内的语句要有一定规范
//for(i = 0;i < 10;i++)这种写法是正确的
//要声明循环对象和循环条件,如果for死循环，并行区域会报错