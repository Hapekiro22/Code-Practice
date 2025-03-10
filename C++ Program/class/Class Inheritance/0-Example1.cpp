#include <iostream>
#include <random>
#include <ctime>
using namespace std;

class Vehicle {
    int vehicleId;
    string name;
public:
    Vehicle(string name): name{name} {
        // 生成随机数
        default_random_engine e((unsigned)time(nullptr));
        vehicleId = e();
        cout << "This is a Vehicle " << vehicleId << endl;
    }
    const int getVehicleId() const {
        return vehicleId;
    }
    const string &getName() const {
        return name;
    }
};

class Car: public Vehicle {
public:
    // 调用基类的构造函数
    Car(const string &name) : Vehicle(name) {}
    void printInfo() {
        // 通过公有方法调用私有成员
        cout << "VehicleId: " << getVehicleId() << endl;
        cout << "VehicleName: " << getName() << endl;
    }
};

int main(){
    Car car = Car("car1");
    car.printInfo();
}

//CPP继承中，父类被称基类，子类被称为派生类
//派生类继承了基类的所有成员，包括私有成员，但是不能直接访问私有成员
//派生类可以继承除构造函数和析构函数之外的所有成员