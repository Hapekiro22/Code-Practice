#include <iostream>

using namespace std;

class Base {
    
    public:
        int publicVar;
    protected:
        int protectedVar;
    private:
        int privateVar;

    public:
        void publicMethod() {
            cout << "This is a public method" << endl;
        }
    protected:
        void protectedMethod() {
            cout << "This is a protected method" << endl;
        }
    private:
        void privateMethod() {
            cout << "This is a private method" << endl;
        }
    
};

//公有继承
//基类的公有成员在派生类中仍然是公有的
//基类的保护成员在派生类中仍然是保护的
//基类的私有成员在派生类中是不可见的

class PublicDerived : public Base {
    public:
        void print() {
            cout << "publicVar: " << publicVar << endl;
            cout << "protectedVar: " << protectedVar << endl;
            // cout << "privateVar: " << privateVar << endl; // Error
            publicMethod();
            protectedMethod();
            // privateMethod(); // Error
        }
};

//保护继承
//基类的公有成员在派生类中变为保护的
//基类的保护成员在派生类中仍然是保护的
//基类的私有成员在派生类中是不可见的

class ProtectedDerived : protected Base {
    public:
        void print() {
            cout << "publicVar: " << publicVar << endl;
            cout << "protectedVar: " << protectedVar << endl;
            // cout << "privateVar: " << privateVar << endl; // Error
            publicMethod();
            protectedMethod();
            // privateMethod(); // Error
        }
};

//私有继承
//基类的公有成员在派生类中变为私有的
//基类的保护成员在派生类中变为私有的
//基类的私有成员在派生类中是不可见的

class PrivateDerived : private Base {
    public:
        void print() {
            cout << "publicVar: " << publicVar << endl;
            cout << "protectedVar: " << protectedVar << endl;
            // cout << "privateVar: " << privateVar << endl; // Error
            publicMethod();
            protectedMethod();
            // privateMethod(); // Error
        }
};

//在class名称后加上final关键字，表示该类不能被继承

class FinalClass final {
    public:
        void print() {
            cout << "This is a final class" << endl;
        }
};

