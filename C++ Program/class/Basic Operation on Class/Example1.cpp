#include <iostream>
#include <string>
using namespace std;

class Stock{
    string name;
    int shares;
    public:
    //    Stock(const string &name, int shares) : name(name), shares(shares) {}
        Stock(const string &name, int shares) : name{name}, shares{shares} {}
        Stock(){};
        Stock(const Stock& stock){
            this->name = stock.name;
            this->shares = stock.shares;
        }
        const string &getName() const {
            return name;
        }
        int getShares() const {
            return shares;
        }
        void setName(const string &name) {
            Stock::name = name;
        }
        void setShares(int shares) {
            Stock::shares = shares;
        }
        ~Stock() {
            cout << "destructor" << endl;
        }
};

void display(Stock s) {
    cout << s.getName() << " " << s.getShares() << endl;
}

int main()
{
    //Initilize
    Stock s{"world cabbage", 250};
    Stock ss("world cabbage", 250);
    Stock sss = Stock("world cabbage", 250);
    Stock s1;   // 隐式构造（调用默认构造函数，即没有参数的构造函数）
    // Stock s2(); // 别这么干，会被认为是声明了一个返回Stock类型的函数

    //假设我们把一个已有变量通过函数返回出去，从函数返回变量时，将调用该变量的拷贝构造函数，创建出一个临时变量，
    //而当你用一个新定义的变量来接收时，新变量会把这片临时变量的空间作为它自己的空间，即为初始化。

    //而如果直接返回一个临时变量，则可以直接调用拷贝构造函数，不需要再调用一次拷贝构造函数，这样就可以避免一次拷贝构造函数的调用。


    //Operator
    Stock s2 = s; //调用拷贝构造函数
    cout << s2.getName() << " " << s2.getShares() << endl;
    s2.setName("hello world");
    cout << s2.getName() << " " << s2.getShares() << endl;
    //赋值本质上是调用拷贝构造函数


    //Copy
    //发生对象的传递时，会调用拷贝构造函数
    display(s2);
}