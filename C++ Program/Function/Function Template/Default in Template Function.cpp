#include <iostream>
using namespace std;

template <typename T,typename U = T>
T convert(U value)
{
    return static_cast<T>(value);
}

int main()
{
    //默认第二个参数为第一个参数
    double d = convert<double>(10);
    cout << "Converted value: " << d << endl;

    //显式指定第二个参数
    int i = convert<int, double>(3.14);
    cout << "Converted value: " << i << endl;

    return 0;

}