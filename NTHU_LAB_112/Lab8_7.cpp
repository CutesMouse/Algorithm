#include <iostream>
#include <vector>
using namespace std;

int n;
int ans = -1;
vector<int> edge[200001];
int siz[200001] = {0};

void dfs(int node, int parent) {
    siz[node] = 1;
    int mx = -1;
    for (int v : edge[node]) {
        if (v == parent) continue;
        dfs(v, node);
        siz[node] += siz[v];
        mx = max(mx, siz[v]);
    }
    mx = max(mx, n - siz[node]);
    if (mx <= n/2) ans = node;
}

int main() {
    int a, b;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    dfs(1, 0);
    cout << ans;
}
