#include <iostream>
using namespace std;

int dsu[100001];

int find_root(int k) {
    if (dsu[k] == k) return k;
    return dsu[k] = find_root(dsu[k]);
}

void group(int a, int b) {
    int ga = find_root(a);
    int gb = find_root(b);
    if (ga == gb) return;
    dsu[ga] = gb;
}

bool same_group(int a, int b) {
    return find_root(a) == find_root(b);
}

int main() {
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dsu[i] = i;
    while (m--) {
        cin >> a >> b >> c;
        group(a, b);
    }
    bool ans[100001] = {0};
    int r = 0;
    for (int i = 1; i <= n; i++) ans[find_root(i)] = 1;
    for (int i = 1; i <= n; i++) {
        r += ans[i];
    }
    cout <<r;
}
