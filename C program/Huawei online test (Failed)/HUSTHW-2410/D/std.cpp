#include <iostream>
#include <cstring>
using namespace std;

int n;
char s[10][10];
int cnt[10][10];

bool check() {
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i][j] == '*') {
                cnt[i - 1][j - 1]++;
                cnt[i - 1][j]++;
                cnt[i - 1][j + 1]++;
                cnt[i][j - 1]++;
                cnt[i][j + 1]++;
                cnt[i + 1][j - 1]++;
                cnt[i + 1][j]++;
                cnt[i + 1][j + 1]++;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(isdigit(s[i][j]) && cnt[i][j] != s[i][j] - '0') {
                return false;
            }
        }
    }
    return true;
}

void dfs(int step) {
    if(step == n * n + 1) {
        if(check() == false) return;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i][j] == '*') cout << '*';
                else cout << cnt[i][j];
            }
            cout << endl;
        }
        exit(0);
    }
    int x = (step - 1) / n + 1;
    int y = (step - 1) % n + 1;
    if(s[x][y] != '?') dfs(step + 1);
    else {
        s[x][y] = '*';
        dfs(step + 1);
        s[x][y] = '?';
        dfs(step + 1);
    }
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> s[i][j];
        }
    }
    dfs(1);
    return 0;
}