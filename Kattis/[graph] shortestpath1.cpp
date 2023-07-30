#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    int n, m, q, s;
    int u, v, w;
    int qp;
    typedef pair<int, int> p;
    typedef priority_queue<p, vector<p>, greater<>> pq;
    while (cin >> n >> m >> q >> s && n) {
        vector<p> eg[10000];
        int step[10000];
        memset(step, -1, sizeof(int)*n);

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            eg[u].emplace_back(v, w);
        }

        pq queue;
        queue.emplace(0, s);
        step[s] = 0;
        while (!queue.empty()) {
            p info = queue.top();
            queue.pop();
            if (step[info.second] != info.first) continue;
            for (p edge : eg[info.second]) {
                int to = edge.first;
                int weight = edge.second;
                if (step[to] == -1 || step[to] > weight + step[info.second]) {
                    step[to] = weight + step[info.second];
                    queue.emplace(weight + step[info.second], to);
                }
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> qp;
            if (step[qp] == -1) cout << "Impossible\n";
            else cout << step[qp] << "\n";
        }
        cout << "\n";
    }
}
