#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
char input[10][10], output[10][10];
int cnt[10][10];

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();
    inf.readEoln();
    for(int i = 1; i <= n; i++) {
        string line = inf.readString();
        for(int j = 1; j <= n; j++) {
            input[i][j] = line[j - 1];
        }
        line = ouf.readString();
        for(int j = 1; j <= n; j++) {
            output[i][j] = line[j - 1];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(input[i][j] != '?' && input[i][j] != output[i][j]) {
                quitf(_wa, "Expected %c, found %c at (%d, %d)", input[i][j], output[i][j], i, j);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(output[i][j] == '*') {
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
            if(isdigit(input[i][j]) && cnt[i][j] != input[i][j] - '0') {
                quitf(_wa, "Expected %d, found %d at (%d, %d)", input[i][j] - '0', cnt[i][j], i, j);
            }
        }
    }
    quitf(_ok, "Accepted");
    return 0;
}