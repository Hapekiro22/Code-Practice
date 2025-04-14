#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <stdexcept>

int counter = 0;
std::mutex mtx; // 保护counter

void increase_proxy(int time, int id) {
    for (int i = 0; i < time; i++) {
        mtx.lock();
        // 线程1上锁成功后，抛出异常：未释放锁
        if (id == 1) {
            throw std::runtime_error("throw excption....");
        }
        // 当前线程休眠1毫秒
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter++;
        mtx.unlock();
    }
}

void increase(int time, int id) {
    try {
        increase_proxy(time, id);
    }
    catch (const std::exception& e){
        std::cout << "id:" << id << ", " << e.what() << std::endl;
    }
}

int main(int argc, char** argv) {
    std::thread t1(increase, 10, 1);
    std::thread t2(increase, 10, 2);
    t1.join();
    t2.join();
    std::cout << "counter:" << counter << std::endl;
    return 0;
}

//用std::mutex来创建互斥锁，保护共享资源
//但是在线程1中抛出异常，导致互斥锁未解锁，线程2无法获取互斥锁，导致死锁
//这时程序会输出id:1, throw excption....，并且无法继续执行
//在实际应用中，需要保证互斥锁的使用是正确的，否则会导致死锁等问题