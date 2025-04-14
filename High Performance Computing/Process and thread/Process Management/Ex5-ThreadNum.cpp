#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main()
{
    unsigned int n = std::thread::hardware_concurrency();
    cout << "Number of threads supported: " << n << endl;

    vector<std::thread> threads;
    for(unsigned int i = 0; i < n; ++i) {
        threads.push_back(std::thread([](){
            cout << "Thread ID: " << std::this_thread::get_id() << endl;
        }));
    }

    for(auto& t : threads) {
        t.join();
    }

    return 0;
}