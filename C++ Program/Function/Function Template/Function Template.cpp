#include <iostream>
using namespace std;

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "Before Swap: " << a << " " << b << endl;
    mySwap(a, b);
    cout << "After Swap: " << a << " " << b << endl;

    float x = 10.5, y = 20.5;
    cout << "Before Swap: " << x << " " << y << endl;
    mySwap(x, y);
    cout << "After Swap: " << x << " " << y << endl;

    return 0;
}

//函数模板可以用于多种数据类型，而不需要重载函数