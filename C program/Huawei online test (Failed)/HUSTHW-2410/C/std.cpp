#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 100000 + 7;

int n, k;
struct Course {
    int score, credit;
}c[MAXN];

int main() {
    cin >> n >> k;
    int TotalScore = 0, TotalCredit = 0;
    for(int i = 1; i <= k; i++) {
        int CourseScore, CourseCredit;
        cin >> CourseScore >> CourseCredit;
        TotalScore += CourseScore * CourseCredit;
        TotalCredit += CourseCredit;
    }
    for(int i = 1; i <= n - k; i++) {
        cin >> c[i].score >> c[i].credit;
    }
    auto comp = [](Course a, Course b) -> bool {
        return a.score > b.score;
    };
    sort(c + 1, c + n - k + 1, comp);
    for(int i = 1; i <= n - k; i++) {
        if(1.0 * c[i].score > 1.0 * TotalScore / TotalCredit) {
            TotalScore += c[i].score * c[i].credit;
            TotalCredit += c[i].credit;
        }
    }
    double ans = 1.0 * TotalScore / TotalCredit;
    ans = round(ans * 100) / 100;
    printf("%.2lf\n", ans);
    return 0;
}