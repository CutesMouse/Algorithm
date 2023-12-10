#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int n;
vector<int> edge[200001];
int siz[200001] = {0};
int dp[200001] = {0};

//find siz
void dfs1(int u, int parent) {
    siz[u] = 1;
    for (int v : edge[u]) {
        if (v == parent) continue;
        dfs1(v, u);
        siz[u] += siz[v];
    }
}

//find dp[1]
void dfs2(int u, int parent, int dis) {
    dp[1]+=dis;
    for (int v : edge[u]) {
        if (v == parent) continue;
        dfs2(v, u, dis+1);
    }
}

//find dp[i] for all i in [2, n]
void dfs3(int u, int parent) {
    for (int v : edge[u]) {
        if (v == parent) continue;
        dp[v] = dp[u] + n - 2 * siz[v];
        dfs3(v, u);
    }
}

signed main() {
    int a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    dfs1(1, -1);
    dfs2(1, -1, 0);
    dfs3(1, -1);
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
}
