#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dsu[100001];

int find_root(int k) {
    if (dsu[k] == k) return k;
    return dsu[k] = find_root(dsu[k]);
}

bool same_group(int a, int b) {
    return find_root(a) == find_root(b);
}

void group(int a, int b) {
    if (same_group(a, b)) return;
    dsu[find_root(a)] = find_root(b);
}

int main() {
    int n, m, a, b, c;
    long long int ans = 0;
    cin >> n >> m;
    vector<pair<long long int, pair<int, int>>> roads;
    while (m--) {
        cin >> a >> b >> c;
        roads.push_back({c, {a, b}});
    }
    sort(roads.begin(), roads.end());
    for (int i = 0; i <= n; i++) dsu[i] = i;
    for (int i = 0; i < roads.size(); i++) {
        if (same_group(roads[i].second.first, roads[i].second.second)) continue;
        ans += roads[i].first;
        group(roads[i].second.first, roads[i].second.second);
    }
    for (int i = 1; i <= n; i++) {
        if (!same_group(1, i)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << ans;
}
