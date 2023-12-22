#include<iostream>
#define MAXN 200000
#define INF (1<<28)
using namespace std;

int tree[4*MAXN];
int a[MAXN];
int n;

void pull(int id) {
    tree[id] = max(tree[id<<1], tree[id<<1|1]);
}

void build_tree(int l, int r, int id = 1) {
    if (l == r) {
        tree[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build_tree(l, m, id<<1);
    build_tree(m+1, r, id<<1|1);
    pull(id);
}

int query(int x, int l, int r, int id = 1) {
    if (tree[id] < x) return INF;
    if (l == r) {
        return l;
    }
    int m = (l + r) / 2;
    int ans = query(x, l, m, id<<1);
    if (ans != INF) return ans;
    return query(x, m+1, r, id<<1|1);
}

void modify(int p, int val, int l, int r, int id = 1) {
    if (p < l || r < p) return;
    if (l == r) {
        tree[id] -= val;
        return;
    }
    int m = (l + r) / 2;
    modify(p, val, l, m, id<<1);
    modify(p, val, m+1, r, id<<1|1);
    pull(id);
}

int main() {
    int m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build_tree(0, n-1);
    while (m--) {
        cin >> k;
        int ans = query(k, 0, n-1);
        if (ans == INF) cout << 0;
        else {
            modify(ans, k, 0, n-1);
            cout << ans+1;
        }
        cout << " ";
    }
}
