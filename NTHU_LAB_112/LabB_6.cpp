#include <iostream>
#define INF (1LL<<50)
#define MAXN 405
#define int long long int
using namespace std;

//從i到j清除的最小成本
int dp[MAXN][MAXN];
int a[MAXN];
int px[MAXN];
int n;

int sum_from(int i, int j) {
    return px[j + 1] - px[i];
}

int dfs(int i, int j) {
    if (dp[i][j] != INF) return dp[i][j];
    for (int bp = i; bp < j; bp++) {
        dp[i][j] = min(dp[i][j], dfs(i, bp) + dfs(bp+1, j));
    }
    return dp[i][j] = dp[i][j] + sum_from(i, j);
}

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INF;
        }
    }
    px[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        px[i+1] = px[i] + a[i];
    }
    for (int i = 0; i < n-1; i++) {
        dp[i][i+1] = a[i] + a[i+1];
        dp[i][i] = 0;
    }
    dp[n-1][n-1] = 0;
    cout << dfs(0, n-1) << endl;
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
}
