#include <iostream>
#include <queue>
using namespace std;

int main() {
    typedef long long int ll;
    typedef pair<ll, ll> p;
    vector<p> edge[100001];
    ll n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge[a].emplace_back(b, c);
    }
    ll dis[100001];
    for (int i = 0; i <= n; i++) dis[i] = -1;
    priority_queue<p, vector<p>, greater<p>> ppq;
    ppq.emplace(0, 1);
    dis[1] = 0;
    while (ppq.size()) {
        auto [cost, pos] = ppq.top();
        ppq.pop();
        if (dis[pos] != cost) continue;
        for (auto &[dest, c] : edge[pos]) {
            if (dis[dest] == -1 || (cost + c < dis[dest])) {
                dis[dest] = cost + c;
                ppq.emplace(cost + c, dest);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dis[i] << " ";
}
