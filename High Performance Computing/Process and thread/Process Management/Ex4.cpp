//调用join函数时，会在一个线程上等待另一个线程的结束。如果不调用join函数，主线程会立即结束，从而导致子线程也会立即结束。

#include <iostream>
#include <thread>
#include <cstdint>

using namespace std;

void output(int i)
{
    cout << i << endl;
}

int main()
{
    for(uint8_t i = 0;i < 4;i++)
    {
        thread t(output,i);
        t.join();
    }

    getchar();
    return 0;
}

//由于调用了join函数，所以主线程会等待子线程的结束，所以输出结果是顺序的。