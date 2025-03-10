#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // 隐式实例化 - 编译器自动推断类型
    cout << "Implicit: " << add(5, 3) << endl;
    
    // 显式实例化 - 明确指定类型
    cout << "Explicit: " << add<double>(5, 3) << endl;
    
    return 0;
}

