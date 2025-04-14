#include <stdio.h>
#include <omp.h>

int main()
{
    int i = 0;
    #pragma omp for
        for(i = 0;i < 10;i++)
        {
            printf("i = %d\n",i);
        }

    return 0;
}



//如果只用for并不声明parallel，那么只有一个线程会执行for循环
//如果用了parallel，那么for循环会被分配给不同的线程