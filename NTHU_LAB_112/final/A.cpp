#include <iostream>
using namespace std;

// 前i個apple能不能湊出左右相差j
bool dp[101][1000001] = {0};
int h[100];

int main() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> h[i];
    }
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1000000; j++) {
            dp[i][j] |= dp[i-1][abs(j-h[i-1])];
            if (j + h[i-1] <= 1000000) dp[i][j] |= dp[i-1][j+h[i-1]];
            //cout << dp[i][j] <<" ";
        }
        //cout << endl;
    }
    for (int i = 0; i <= 1000000; i++) {
        if (dp[n][i]) {
            cout << i;
            return 0;
        }
    }
}
