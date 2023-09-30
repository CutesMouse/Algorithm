#include <iostream>
using namespace std;

// first dimension: n
// second dimension: is the final edge with 2 extra blocks
int dp[35][2];

int main() {
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[2][0] = 3;
    dp[2][1] = 2;

    for (int i = 3; i <= 30; i++) {
        dp[i][0] = dp[i-2][1] + dp[i-2][0] * 3;
        dp[i][1] = dp[i-2][0] * 2 + dp[i-2][1];
    }

    int n;
    while (cin >> n && n != -1) {
        cout << dp[n][0] << endl;
    }
}
