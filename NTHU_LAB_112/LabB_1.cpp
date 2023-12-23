#include <iostream>
#define int long long int
#define INF (1LL<<50)
using namespace std;

int n, x;

pair<int, int> dp[1048576+1] = {};
int w[20];

int lowbit(int x) {
    return (-x) & x;
}

pair<int, int> dfs(int used) {
    if (dp[used].first != INF && dp[used].second != INF) return dp[used];
    if (used == ((1<<n)-1)) {
        return {0, 0};
    }
    auto ans = dp[used];
    int S = (~used) & ((1<<n)-1);
    for (int i = 0; S; S ^= i) {
        i = lowbit(S);
        auto calc = dfs(used^i);
        if (w[__lg(i)] + calc.second <= x) {
            ans = min(ans, {calc.first, w[__lg(i)] + calc.second});
        } else {
            ans = min(ans, {calc.first+1, w[__lg(i)]});
        }
    }
    return dp[used] = ans;
}

signed main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < (1<<n)-1; i++) dp[i] = {INF, INF};
    cout << dfs(0).first + (dp[0].second != 0);
}
