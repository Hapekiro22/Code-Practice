#include <iostream>
using namespace std;

class NonConstructor {
    public:
        int x;
};

int main()
{
    NonConstructor obj;
    cout << obj.x;
    return 0;
}


//在上面的代码中，我们定义了一个类NonConstructor，它没有构造函数。
//没有构造函数时，编译器会自动提供一个默认构造函数。
//默认构造函数不执行任何操作，它只是分配内存并初始化数据成员的值。