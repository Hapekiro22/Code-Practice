#include <iostream>
#include <string>
using namespace std;

int main() {
    string id;
    cin >> id;
    
    auto IsUnderGraduate = [](string s) -> bool {
        return s[0] == 'U';
    };
    auto EntraceYear = [](string s) -> int {
        return stoi(s.substr(1, 4));
    };

    if(IsUnderGraduate(id) && (EntraceYear(id) == 2023 || EntraceYear(id) == 2024)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}