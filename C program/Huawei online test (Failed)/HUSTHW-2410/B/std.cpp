#include <iostream>
using namespace std;

int main() {
    int k, x0, y0, x1, y1;
    cin >> k >> x0 >> y0 >> x1 >> y1;
    int dist = abs(x0 - x1) + abs(y0 - y1);
    if(dist > k) {
        cout << "No" << endl;
    } else {
        if((k - dist) % 2 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}