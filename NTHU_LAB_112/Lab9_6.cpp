#include <iostream>
#include <vector>
#include <algorithm>
#define INF (1LL<<60)
using namespace std;

int n, m;
int a, b;
long long int x;
vector<pair<int, long long int>> edge_to[2501];
vector<pair<int, long long int>> edge_from[2501];
long long int dis[2501];
bool path1[2501] = {0};
bool path2[2501] = {0};

void dfs(int pos, bool* path, vector<pair<int, long long int>>* edge) {
    if (path[pos]) return;
    path[pos] = true;
    for (auto &[nxt, cost] : edge[pos]) {
        dfs(nxt, path, edge);
    }
}

bool relax() {
    bool update = false;
    for (int i = 1; i <= n; i++) {
        for (auto &[pos, cost] : edge_to[i]) {
            if (path1[pos] && path2[pos] && dis[i] + cost < dis[pos]) {
                update = true;
                dis[pos] = dis[i] + cost;
            }
        }
    }
    return update;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < 2501; i++) dis[i] = INF;
    dis[1] = 0;
    while (m--) {
        cin >> a >> b >> x;
        edge_to[a].emplace_back(b, -x);
        edge_from[b].emplace_back(a, -x);
    }
    dfs(1, path1, edge_to);
    dfs(n, path2, edge_from);
    for (int i = 0; i < n; i++) {
        relax();
    }
    if (relax()) cout << -1;
    else {
        cout << -(dis[n]);
    }
}
