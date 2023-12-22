#include <iostream>
#define MAXN 200000
#define int long long int
using namespace std;

struct Node {
    int sum, max_prefix, max_postfix, mcs;
    Node operator+(Node r) {
        int mp = max(max_prefix, sum + r.max_prefix);
        int ms = max(r.max_postfix, r.sum + max_postfix);
        int mmcs = max(max_postfix + r.max_prefix, max(mcs, r.mcs));
        int mdata = sum + r.sum;
        return {mdata, mp, ms, mmcs};
    }
};

Node tree[4 * MAXN];
int a[MAXN];

void pull(int id) {
    tree[id] = tree[id<<1] + tree[id<<1|1];
}

void build_tree(int l, int r, int id = 1) {
    if (l == r) {
        tree[id] = {a[l], max(0LL, a[l]), max(0LL, a[l]), max(0LL, a[l])};
        return;
    }
    int m = (l + r) / 2;
    build_tree(l, m, id<<1);
    build_tree(m+1, r, id<<1|1);
    pull(id);
}

void modify(int p, int val, int l, int r, int id = 1) {
    if (p < l || p > r) return;
    if (l == r) {
        tree[id] = {val, max(0LL, val), max(0LL, val), max(0LL, val)};
        return;
    }
    int m = (l + r) / 2;
    modify(p, val, l, m, id<<1);
    modify(p, val, m+1, r, id<<1|1);
    pull(id);
}

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build_tree(0, n-1);
    int a, b;
    while(m--) {
        cin >> a >>b;
        modify(a-1, b, 0, n-1);
        cout << tree[1].mcs << endl;
    }
}
