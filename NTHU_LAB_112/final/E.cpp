#include <iostream>
#include <vector>
#define MAXN 100001
#define int long long int
using namespace std;

// 在第i的子分支有被選的情況下的最大分數
int dp[MAXN][2];
int n;
vector<pair<int, int>> edge[MAXN];

int dfs(int u, bool select, int parent = -1) {
    if (dp[u][select] != -1) return dp[u][select];
    dp[u][select] = 0;
    if (select) {
        int standard = 0;
        for (auto [v, w] : edge[u]) {
            if (v == parent) continue;
            standard += max(dfs(v, true, u), dfs(v, false, u));
        }
        for (auto [v, w] : edge[u]) {
            if (v == parent) continue;
            dp[u][select] = max(dp[u][select], standard - max(dfs(v, true, u),
dfs(v, false, u)) + w + dfs(v, false, u));
        }
    } else {
        for (auto [v, w] : edge[u]) {
            if (v == parent) continue;
            dp[u][select] += max(dfs(v, true, u), dfs(v, false, u));
        }
    }
    return dp[u][select];
}

signed main() {
    int u, v, w;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        edge[u].emplace_back(v, w);
        edge[v].emplace_back(u, w);
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    cout << max(dfs(1, false), dfs(1, true));
}
