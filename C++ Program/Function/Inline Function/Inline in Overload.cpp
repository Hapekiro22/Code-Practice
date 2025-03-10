#include <iostream>
#include <string>
using namespace std;

inline int add(int a, int b)
{
    return a + b;
}

inline double add(double a, double b)
{
    return a + b;
}

inline string add(string a, string b)
{
    return a + b;
}

int main()
{
    cout << "Sum of 5 and 3 is " << add(5, 3) << endl;
    cout << "Sum of 5.5 and 3.3 is " << add(5.5, 3.3) << endl;
    cout << "Sum of Hello and World is " << add("Hello", "World") << endl;
    return 0;
}

//内联函数可以重载，即可以定义多个同名的内联函数，只要它们的参数列表不同即可。