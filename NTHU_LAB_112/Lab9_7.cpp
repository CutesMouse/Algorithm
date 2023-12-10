#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> edge[100001];
int in[100001] = {0};

int main() {
    cin >> n >> m;
    int a, b;
    while (m--) {
        cin >> a >> b;
        in[b]++;
        edge[a].emplace_back(b);
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) q.emplace(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        ans.emplace_back(u);
        for (auto v : edge[u]) {
            if (--in[v] == 0) q.emplace(v);
        }
    }
    if (ans.size() == n) {
        for (auto iter = ans.begin(); iter != ans.end(); iter++) cout << *iter << " ";
    } else cout << "IMPOSSIBLE";
}
