#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <stdexcept>

using namespace std;

int counter = 0;
std::mutex mtx; 

void increace_proxy(int time,int id)
{
    for(int i = 0;i < time;i++)
    {
        std::lock_guard<std::mutex> lk(mtx);
        
        if(id == 1)
        {
            throw std::runtime_error("throw excption....");
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        counter++;
    }
}

void increase(int time,int id)
{
    try
    {
        increace_proxy(time,id);
    }
    catch(const std::exception& e)
    {
        std::cout << "id:" << id << ", " << e.what() << std::endl;
    }
}

int main()
{
    std::thread t1(increase,10,1);
    std::thread t2(increase,10,2);
    t1.join();
    t2.join();
    std::cout << "counter:" << counter << std::endl;
    return 0;
}

//使用std::lock_guard来创建互斥锁，保护共享资源

//std::lock_guard是一个RAII风格的模板类，用于管理互斥锁的生命周期
//在构造函数中，std::lock_guard会锁定互斥锁，而在析构函数中会解锁互斥锁
//只要lockguard超出作用域，就会自动调用析构函数，解锁互斥锁
//这样就可以避免忘记解锁互斥锁，导致死锁等问题
//在这个例子中，线程1抛出异常，但是互斥锁会在异常处理中被解锁，线程2可以继续执行
//输出结果为id:1, throw excption....，counter:10