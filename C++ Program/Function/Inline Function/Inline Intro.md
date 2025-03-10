# C++ 内联函数详解

内联函数（Inline Function）是 C++ 中一种特殊的函数，编译器会尝试在调用点展开函数体，而不是进行普通的函数调用。这可以减少函数调用的开销，提高程序的执行效率。

## 1. 基本语法

内联函数可以通过 `inline` 关键字声明：

```cpp
#include <iostream>
using namespace std;

// 声明一个内联函数
inline int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(5, 3);  // 编译器可能会将这里替换为 int result = 5 + 3;
    cout << "Result: " << result << endl;
    return 0;
}
```

## 2. 类中的内联函数

在类定义中直接定义的成员函数会自动成为内联函数

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, height;
public:
    // 内联成员函数（在类定义中直接定义）
    Rectangle(int w, int h) : width(w), height(h) {}
    
    int getArea() {
        return width * height;
    }
};

int main() {
    Rectangle rect(5, 3);
    cout << "Area: " << rect.getArea() << endl;  // getArea() 是内联的
    return 0;
}
```

## 3. 类外定义内联成员函数

也可以在类外使用 inline 关键字定义内联成员函数：

```cpp
#include <iostream>
using namespace std;

class Rectangle {
private:
    int width, height;
public:
    Rectangle(int w, int h);
    int getArea();
};

// 类外定义内联构造函数
inline Rectangle::Rectangle(int w, int h) : width(w), height(h) {}

// 类外定义内联成员函数
inline int Rectangle::getArea() {
    return width * height;
}

int main() {
    Rectangle rect(5, 3);
    cout << "Area: " << rect.getArea() << endl;
    return 0;
}

```

## 6. 内联函数与重载

内联函数也可以被重载：

```cpp
#include <iostream>
#include <string>
using namespace std;

// 重载内联函数
inline int add(int a, int b) {
    return a + b;
}

inline double add(double a, double b) {
    return a + b;
}

inline string add(const string& a, const string& b) {
    return a + b;
}

int main() {
    cout << "5 + 3 = " << add(5, 3) << endl;
    cout << "4.2 + 3.5 = " << add(4.2, 3.5) << endl;
    cout << "\"Hello\" + \"World\" = " << add(string("Hello"), string("World")) << endl;
    return 0;
}
```

## 内联函数总结

### 1.使用场景：

简短、频繁调用的函数
性能关键的代码段
访问类的私有成员的小函数

### 2.优点：

减少函数调用开销
可能提高缓存命中率
允许编译器进行更多优化

### 3.缺点：

可能增加可执行文件大小
过度使用会导致代码臃肿
复杂的内联函数可能被编译器忽略

### 4.最佳实践：

保持内联函数简短、简单
不要内联包含大量代码或复杂控制流的函数
记住 inline 关键字只是对编译器的建议，编译器可能会忽略它