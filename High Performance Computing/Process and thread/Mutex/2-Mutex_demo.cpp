#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <stdexcept>

using namespace std;

std::mutex mtx;

int counter = 0;
void increase(int time) {
    for(int i = 0;i < time;i++)
    {
        mtx.lock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter++;
        mtx.unlock();
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

//现在在两个线程中使用互斥锁保护共享资源，可以避免数据竞争，输出结果为1000
//在每一次加法操作之前，使用mtx.lock()来锁定互斥锁，操作完成后使用mtx.unlock()来解锁互斥锁
//这样就可以保证在同一时间只有一个线程可以访问共享资源

//这两个线程在任意时刻会有一个线程给counter上锁，另一个线程会等待，直到第一个线程解锁
//这样就保证了counter的操作是原子的，不会出现数据竞争
//在实际应用中，需要保证互斥锁的使用是正确的，否则会导致死锁等问题