#include <iostream>
#include <thread>
#include <cstdint>

using namespace std;

class Task
{
public:
	void operator()(int i)
	{
		cout << i << endl;
	}
};

int main()
{
	
	for (uint8_t i = 0; i < 4; i++)
	{
		Task task;
		thread t(task, i);
		t.detach();	
	}

    getchar();
    return 0;
}