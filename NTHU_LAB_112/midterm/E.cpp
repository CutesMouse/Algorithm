#include <iostream>
#include <queue>
#include <cstring>

#define int long long int
using namespace std;

bool used[2000005];
int d[51];

signed main() {
    memset(used, 0, sizeof used);
    int n, x, k;
    cin >> n >> x >> k;
    for (int i = 0; i < k; i++) cin >> d[i];
    queue<int> q;
    q.emplace(1);
    int level = 0;
    while (q.size()) {
        for (int p = q.size(); p > 0; p--) {
            int s = q.front();
            if (s == x) {
                cout << level;
                return 0;
            }
            q.pop();
            for (int i = 0; i < k; i++) {
                int ns = (s * d[i] - 1) % n + 1;
                if (used[ns]) continue;
                q.emplace(ns);
                used[ns] = true;
            }
        }
        level++;
    }
    cout << "I LOVE TSING HUA";
}
