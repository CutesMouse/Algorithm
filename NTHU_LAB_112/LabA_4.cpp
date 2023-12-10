#include <iostream>
#define MOD (1000000007)
#define int long long int
using namespace std;

int dp[125251][2] = {0};

int add(int a, int b) {
    return (a + b) % MOD;
}

int mod(int a, int m) {

}

signed main() {
    int n;
    cin >> n;
    int sum = n * (n+1) / 2;
    if (sum % 2) {
        cout << 0;
        return 0;
    }
    int x = sum / 2;
    dp[0][0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i <= x; i++) {
            dp[i][j&1] = dp[i][!(j&1)];
            if (i >= j) dp[i][j&1] = add(dp[i][j&1], dp[i-j][!(j&1)]);
        }
    }
    cout << ((dp[x][(n&1)] % MOD) * 500000004) % MOD;
}
