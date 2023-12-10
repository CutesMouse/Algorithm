#include <iostream>
#define MAXN 200001
using namespace std;

int dsu[MAXN];

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
    int n, q;
    cin >> n >> q;
    int a, b;
    for (int i = 0; i <= n; i++) dsu[i] = i;
    while (q--) {
        cin >> a >> b;
        group(a-1, b);
    }
    if (same_group(0, n)) cout << "Yes";
    else cout << "No";
}
