#include <stdio.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            printf("Section 1 Thread id = %d\n",omp_get_thread_num());
        }
        #pragma omp section
        {
            printf("Section 2 Thread id = %d\n",omp_get_thread_num());
        }
        #pragma omp section
        {
            printf("Section 3 Thread id = %d\n",omp_get_thread_num());
        }
        #pragma omp section
        {
            printf("Section 4 Thread id = %d\n",omp_get_thread_num());
        }
    }

    cout << "The next Section"  << endl;

    #pragma omp parallel 
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Section 5 Thread id = %d\n",omp_get_thread_num());
            }
            #pragma omp section
            {
                printf("Section 6 Thread id = %d\n",omp_get_thread_num());
            }
            #pragma omp section
            {
                printf("Section 7 Thread id = %d\n",omp_get_thread_num());
            }
            #pragma omp section
            {
                printf("Section 8 Thread id = %d\n",omp_get_thread_num());
            }
        }
    }

    return 0;
}


//sections指令会将其下面的代码块分配给不同的线程
//每个section都会被分配给不同的线程

//不同secitons之间是串行的

//用 for 语句来分摊是由系统自劢迚行，叧要每次循环间没有时间上的差距，那么分摊是很均匀的，
//使用 section 来划分线程是一种手工划分线程的方式，最终并行性的好坏得依赖亍程序员。
