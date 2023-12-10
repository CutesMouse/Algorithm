#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int color[100001];
int n, m;
vector<int> edge[100001];

bool dfs(int pos, int type) {
    if (color[pos]) {
        if (color[pos] == type) return true;
        return false;
    }
    color[pos] = type;
    for (int edg : edge[pos]) {
        if (dfs(edg, 1 + (type == 1))) continue;
        return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    memset(color, 0, sizeof color);
    int a, b;
    while (m--) {
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i]) continue;
        if (!dfs(i, 1)) {
            cout << "MANY";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
}
