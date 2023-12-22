#include <iostream>
#define MAXN 200000
#define INF (1<<30)
using namespace std;

int tree[4*MAXN];
int m[MAXN];
int n;

void pull(int l, int r, int id) {
    tree[id] = min(tree[id<<1|0], tree[id<<1|1]);
}

void build_tree(int l, int r, int id = 1) {
    if (l == r) {
        tree[id] = m[l];
        return;
    }
    int m = (l + r) / 2;
    build_tree(l, m, id<<1|0);
    build_tree(m+1, r, id<<1|1);
    pull(l, r, id);
}

int query(int ql, int qr, int l, int r, int id = 1) {
    if (qr < l || ql > r) return INF;
    //printf("tree: %d, val: %d\n", id, tree[id]);
    if (ql <= l && r <= qr) return tree[id];
    int m = (l + r) / 2;
    return min(query(ql, qr, l, m, id<<1|0), query(ql, qr, m+1, r, id<<1|1));
}

void modify(int p, int val, int l, int r, int id = 1) {
    if (p < l || p > r) return;
    if (l == r) {
        tree[id] = val;
        return;
    }
    int m = (l + r) / 2;
    modify(p, val, l, m, id<<1|0);
    modify(p, val, m+1, r, id<<1|1);
    pull(l, r, id);
}

int main() {
    int q, a, b, c;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> m[i];
    build_tree(0, n-1);
    while (q--) {
        cin >> a >> b >> c;
        if (a == 1) modify(b-1, c, 0, n-1);
        else cout << query(b-1, c-1, 0, n-1) << endl;
    }
}
