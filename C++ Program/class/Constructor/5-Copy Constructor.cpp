#include <iostream>
#include <string>
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

        // Copy Constructor
        Person(const Person &p) {
            name = p.name;
            age = p.age;
            cout << "Copy Constructor" << endl;
        }

        //析构函数
        ~Person() {
            delete &name;
            cout << "Destructor" << endl;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }

        
        void changeName(string n) {
            name = n;
        }

};

int main() {
    Person p1("John", 25);
    Person p2 = p1;
    p1.display();
    p2.display();
    p1.changeName("Doe");
    p1.display();
    p2.display();
    return 0;
}

//拷贝构造函数的特征
//1.函数名与类名相同
//2.参数为常量引用
//3.没有返回值