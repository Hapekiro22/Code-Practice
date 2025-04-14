#include <iostream>
#include <thread>

using namespace std;

class MyThread 
{
    public:
        void getThreadId()
        {
            cout << "Thread ID:" << this_thread::get_id() << endl;
        }
        void sleepThread()
        {
            cout << "Thread ID:" << this_thread::get_id() << " is going to sleep" << endl;
            this_thread::sleep_for(chrono::seconds(5));
            cout << "Thread ID:" << this_thread::get_id() << " is awake" << endl;
        }
};

int main()
{
    MyThread obj;
    thread t1(&MyThread::getThreadId, &obj);
    t1.join();

    thread t2(&MyThread::sleepThread, &obj);
    t2.join();
    return 0;
}