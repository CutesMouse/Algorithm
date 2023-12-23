#include <iostream>
#include <vector>
#define MAXN 100000+1
#define MOD (1000000007)
#define int long long int
using namespace std;

// 第i個頂點以下 塗黑(0)/白(1)的方法數
int dp[MAXN][2] = {0};
vector<int> edge[MAXN];

int m(int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

int dfs(int u, int color, int parent = -1) {
    if (dp[u][color]) return dp[u][color];
    int ans = 0;
    if (color == 0) {
        int p = 1;
        for (auto v : edge[u]) {
            if (v == parent) continue;
            p = m(p, dfs(v, 1, u));
        }
        ans += p;
    } else {
        int p = 1;
        for (auto v : edge[u]) {
            if (v == parent) continue;
            p = m(p, (dfs(v, 1, u) + dfs(v, 0, u)));
        }
        ans += p;
    }
    return dp[u][color] = ans % MOD;
}

signed main() {
    int N, a, b;
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    cout << (dfs(1, 0) + dfs(1, 1)) % MOD;
}
