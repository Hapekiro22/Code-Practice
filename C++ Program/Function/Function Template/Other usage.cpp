#include <iostream>
using namespace std;

template <typename T, int size>
void printArray(T (&arr)[size])
{
    cout << "Array elements:" ;
    for(int i = 0;i < size;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int intArray[5] = {1, 2, 3, 4, 5};
    printArray(intArray);

    double doubleArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    printArray(doubleArray);

    return 0;
}