#include <iostream>
using namespace std;

class Person {
    private:
        string name;
        int age;
    
    public:
        Person(string n, int a) {
            name = n;
            age = a;
            cout << "Parameterized Constructor" << endl;
        }

        ~Person() {
            cout << "Destructor" << endl;
        }
    
};

int main() {
    Person p1("John", 25);
    return 0;
}

//析构函数是在对象销毁是调用的特殊成员函数
//析构函数没有参数，没有返回值
//析构函数的名称是在类名前加上一个波浪号（~）


//如果我们不提供析构函数，编译器会提供一个默认的析构函数
//默认的析构函数不做任何事情
//默认析构函数会按照声明的相反顺序依次调用所有非静态成员的析构函数