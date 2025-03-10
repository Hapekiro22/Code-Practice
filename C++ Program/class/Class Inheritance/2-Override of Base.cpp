#include <iostream>
#include <string>
using namespace std;

class Base {
    public:
        void display() {
            cout << "Display from Base" << endl;
        }
    
};

class Derived : public Base {
    public:
        void display() {
            cout << "Display from Derived" << endl;
        }
};

int main() {
    Derived d;
    d.display();
    
    Base *b = &d;
    b->display();

    d.display();

    return 0;
}

//派生类可以重写基类的成员函数，这样在调用时，会调用派生类的成员函数
//在上面的代码中，派生类Derived重写了基类Base的display()函数
//在调用d.display()时，会调用Derived的display()函数
//在调用b->display()时，会调用Base的display()函数