#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
T max1(T a, T b)
{
    cout << "Using general template" << endl;
    return a > b ? a : b;
}

//为char*类型定义特化版本，特化版本的优先级高于通用版本
template <>
const char* max1<const char *>(const char *a,const char *b)
{
    cout << "Using char* template" << endl;
    return (strcmp(a, b) > 0) ? a : b;
}

int main()
{
    int i = max1(10,20);
    cout << "Max int: " << i << endl;

    const char *s1 = "Hello";
    const char *s2 = "World";
    const char *s = max1(s1, s2);
    cout << "Max string: " << s << endl;

    return 0;
}

//当然，函数模板也可以重载，但是重载的函数模板必顋有不同的参数列表。