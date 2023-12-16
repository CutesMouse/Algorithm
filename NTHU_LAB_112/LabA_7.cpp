#include <iostream>
using namespace std;

int dp[100001][3];
int opt[100001][3];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> opt[i][j];
        }
    }
    for (int j = 0; j < 3; j++) {
        dp[0][j] = opt[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + opt[i][j];
        }
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
}
