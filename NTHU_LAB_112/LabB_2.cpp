#include <iostream>
#include <queue>
#include <bitset>
#define MAXN 50001
using namespace std;

int in[MAXN] = {0};
bitset<MAXN> dp[MAXN] = {0};
vector<int> edge[MAXN];
int n;

int main() {
    int m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        //輸入相反
        edge[b-1].emplace_back(a-1);
        in[a-1]++;
    }
    //拓樸排序
    queue<int> Q;
    for (int i = 0; i < n; i++) {
        dp[i].set(i);
        if (in[i] == 0) {
            Q.emplace(i);
        }
    }
    while (Q.size()) {
        int u = Q.front();
        Q.pop();
        for (auto v : edge[u]) {
            dp[v] |= dp[u];
            if (!--in[v]) Q.emplace(v);
        }
    }
    for (int i = 0; i < n; i++) cout << dp[i].count() <<" ";
}
