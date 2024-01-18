#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#define maxn 2501
using namespace std;

int connect[maxn][maxn];
int n;
int dsu[maxn] = {0};
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> ans;

// k > 0
int find_root(int k) {
    if (!dsu[k]) return k;
    return dsu[k] = find_root(dsu[k]);
}

void group(int a, int b) {
    int gA = find_root(a);
    int gB = find_root(b);
    if (gA == gB) return;
    dsu[gA] = gB;
}


int main() {
    cin >> n;
    int w;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w;
            if (i >= j) continue;
            edges.emplace_back(w, i, j);
        }
    }
    sort(edges.begin(), edges.end());
    for (auto [w, i, j] : edges) {
        if (find_root(i) == find_root(j)) continue;
        group(i, j);
        ans.emplace_back(i, j);
    }
    sort(ans.begin(), ans.end());
    for (auto [i, j] : ans) {
        cout << i << " " << j << endl;
    }
}
