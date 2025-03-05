#include <iostream>
#include <thread>
#include <cstdint>

using namespace std;

int main()
{
    for (int i = 0; i < 4; i++)
    {
        thread t([i]{
            cout << i << endl;
        });
        t.detach();
    }

    getchar();
    return 0;
}

//也可以为lambda表达式创建一个函数对象，然后将其传递给线程构造函数。