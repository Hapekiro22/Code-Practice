#include <iostream>
using namespace std;

template <typename T, typename U>
T convert(U value)
{
    return static_cast<T>(value);
}

int main()
{
    double d = 3.14159265358979323846;
    cout << "Original value: " << d << endl;

    int i = convert<int>(d);
    cout << "Converted value: " << i << endl;

    float f = convert<float>(d);
    cout << "Converted value: " << f << endl;

    return 0;
}

//函数模板中的多个变量
//这里我们定义了一个函数模板，它有两个模板参数。第一个参数T是返回类型，第二个参数U是参数类型。
//在函数体中，我们使用static_cast将参数类型转换为返回类型。
