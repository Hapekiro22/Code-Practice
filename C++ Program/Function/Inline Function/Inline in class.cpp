#include <iostream>

using namespace std;

class Rectangle {
    private:
        int width,height;
    public:
        Rectangle(int w, int h) : width(w), height(h) {}

        int getArea() {
            return width * height;
        }
};

int main() {
    Rectangle rect(5,3);
    cout << "Area is " << rect.getArea() << endl;
    return 0;
}

//在类中定义的函数默认是内联函数，所以在类中定义的函数会被自动视为内联函数。
//如果不希望某个函数成为内联函数，可以在函数定义前加上inline关键字。
//内联函数的定义和声明必须放在一起，否则编译器无法将函数体插入到调用处。