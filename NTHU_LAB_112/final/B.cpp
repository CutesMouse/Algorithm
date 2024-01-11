#include <iostream>
#include <queue>
#define MAXN 100000
#define int long long int
using namespace std;

typedef pair<int, int> p;
int m, n, k;
vector<p> edge[MAXN];
int dis[MAXN];


int short_path(int offset) {
    priority_queue<p, vector<p>, greater<p>> Q;
    for (int i = 0; i < n; i++) dis[i] = -1;
    dis[0] = 0;
    Q.emplace(0, 0);
    while (Q.size()) {
        auto [cost, u] = Q.top();
        Q.pop();
        if (cost != dis[u]) continue;
        if (u == n-1) return cost;
        for (auto [v, w] : edge[u]) {
            w = max(1LL, w - offset);
            if (dis[v] == -1 || dis[v] > cost + w) {
                dis[v] = cost + w;
                Q.emplace(cost + w, v);
            }
        }
    }
    return dis[n-1];

}

template<class Ty, class FuncTy>
pair<int, int> bs(Ty L, Ty R, FuncTy check) {
    if (check(L) == false) return {L-1, L};
    if (check(R) == true) return {R, R+1};
    while (L + 1 < R) {
        Ty mid = L + (R - L) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    return {L, R};
}

signed main() {
    cin >> n >> m >> k;
    int x, y, w;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> w;
        edge[x].emplace_back(y, w);
        edge[y].emplace_back(x, w);
    }
    auto ans = bs(0LL, 1000000000000000000LL, [&](int d) { return
short_path(d) > k; }).second;
    cout << ans;
}
