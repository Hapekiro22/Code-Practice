#include <iostream>
using namespace std;

class Person {
    private:
        string name;
        int age;
    public:
        Person() 
        {
            name = "Unknown";
            age = 0;
            cout << "Default Constructor is called when object is created" << endl;
        }
    
};

int main()
{
    Person p1;
    return 0;
}

/*构造函数是一种特殊的成员函数，用于初始化类的对象。
当创建类的新对象时，构造函数会自动被调用。
构造函数的主要目的是为对象的数据成员分配内存和设置初始值*/

//构造函数没有返回类型，因为它们不返回任何值。
//构造函数的名称与类的名称相同。