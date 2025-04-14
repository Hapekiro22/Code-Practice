#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <stdexcept>

using namespace std;

int counter = 0;
void increase(int time) {
    for(int i = 0;i < time;i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter++;
    }

}

int main()
{
    std::thread t1(increase, 500);
    std::thread t2(increase, 500);
    t1.join();
    t2.join();
    cout << "Counter: " << counter << endl;
    return 0;
}

//多个线程同时访问共享资源，会导致数据竞争，需要使用互斥锁来保护共享资源
//使用std::mutex来创建互斥锁