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
        Person(string n, int a) 
        {
            name = n;
            age = a;
            cout << "Parameterized Constructor is called when object is created" << endl;
        }
};

int main()
{
    Person p1;
    Person p2("David",25);
    return 0;
}

//一个类可以有多个构造函数，这称为构造函数的重载。
//在上面的代码中，我们定义了两个构造函数，一个是默认构造函数，另一个是带有参数的构造函数。
//当我们创建对象p1时，将调用默认构造函数，当我们创建对象p2时，将调用带有参数的构造函数。