#include <iostream>
#include <string>

using namespace std;

class A {
    public:
        int a_;
        A() {
            cout << "A constructor" << endl;
        }

        A(int a) : a_(a) {
            cout << "A constructor with " << a << endl;
        }

};

class B : public A {
    public:
    B() {
        cout << "B constructor" << endl;
    }
};

class B1 : public A {
    public:
    B1() : A(10) {                          //在进入B1的构造函数之前，会先调用A的构造函数
        cout << "B1 constructor" << endl;
    }
};

int main()
{
    B b;

    B1 b1;

    return 0;
}

//如果采用无参构造函数，那么派生类的构造函数会调用基类的无参构造函数
//但这样的话，基类的构造函数就会被调用两次

//避免这种情况，可以考虑提前调用基类的构造函数
//在派生类的构造函数中，可以通过初始化列表的方式，提前调用基类的构造函数

//尽量避免