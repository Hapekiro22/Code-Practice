#include <iostream>
#include <string>
using namespace std;

class Person {
    private:
        string name;
        int age;
    
    public:
        Person(string n,int a,int i): name(n),age(a)
        {
            cout << "Parameterized Constructor is called when object is created" << endl;
        }

        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

int main()
{
    Person p1("David",25,1);
    p1.display();
    return 0;
}

//使用列表初始化成员变量，会更加简洁和直观。
