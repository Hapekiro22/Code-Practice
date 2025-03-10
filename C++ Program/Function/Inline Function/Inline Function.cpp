#include <iostream>

using namespace std;

inline double area(double r)
{
    return 3.14159 * r * r;
}

int main()
{
    double r;
    cout << "Enter radius: ";
    cin >> r;
    cout << "Area is " << area(r) << endl;
    return 0;
}

//内联函数是一种特殊的函数，它在调用时不是通过函数调用的方式，而是直接将函数体插入到调用处。这样可以减少函数调用的开销，提高程序的执行效率。
//内联函数的定义前面加上inline关键字，内联函数的定义和声明必顫放在一起，否则编译器无法将函数体插入到调用处。