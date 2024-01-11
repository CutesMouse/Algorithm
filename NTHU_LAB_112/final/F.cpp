#include <iostream>
#include <vector>
#include <queue>
#define MAXN 100000

using namespace std;

typedef pair<int, int> p;
vector<p> edge[MAXN];

int n;
int dis[MAXN];

void dfs(int u, int parent = -1) {
    for (auto [v, w] : edge[u]) {
        if (v == parent) continue;
        dis[v] = max(dis[u], w);
        dfs(v, u);
    }
}

int main() {
    int u, v, l, q;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >>v >> l;
        edge[u-1].emplace_back(v-1, l);
        edge[v-1].emplace_back(u-1, l);
    }
    cin >> q;
    while (q--) {
        cin >> u >> v;
        dis[u-1] = 0;
        dfs(u-1);
        cout << dis[v-1] << endl;
    }
}


/*int short_path(int bg, int t) {
    priority_queue<p, vector<p>, greater<p>> Q;
    for (int i = 0; i < n; i++) dis[i] = -1;
    dis[bg] = 0;
    Q.emplace(0, bg);
    while (Q.size()) {
        auto [cost, u] = Q.top();
        Q.pop();
        if (cost != dis[u]) continue;
        for (auto [v, w] : edge[u]) {
            if (dis[v] == -1 || dis[v] > cost + w) {
                dis[v] = cost + w;
                Q.emplace(cost + w, v);
            }
        }
    }
    return dis[t];
}*/
