#include <iostream>
#define MAXN 100000
#define int long long int
using namespace std;


typedef pair<int, int> p;

// <val, amt>
struct Node {
    // val, amt
    int val;
    int amt;
    int tag;
};

Node make_node(int val) {
    Node n;
    n.amt = 1;
    n.val = val;
    n.tag = 0;
    return n;
}

Node tree[4*MAXN];
int a[MAXN];
int n;

p get_val(int id) {
    p ans = {tree[id].val, tree[id].amt};
    if (tree[id].tag) ans.first += tree[id].tag;
    return ans;
}

void push(int id) {
    p d = get_val(id);
    tree[id].amt = d.second;
    tree[id].val = d.first;
    tree[id<<1].tag += tree[id].tag;
    tree[id<<1|1].tag += tree[id].tag;
    tree[id].tag = 0;
}

void pull(int id) {
    p L = get_val(id<<1);
    p R = get_val(id<<1|1);
    if (L.first == R.first) {
        L.second += R.second;
    }
    p d = max(L, R);
    tree[id].amt = d.second;
    tree[id].val = d.first;
}

p query(int ql, int qr, int l = 0, int r = n-1, int id = 1) {
    if (ql > r || qr < l) return {0, 0};
    if (ql <= l && r <= qr) return get_val(id);
    push(id);
    int m = (l + r) / 2;
    p L = query(ql, qr, l, m, id<<1);
    p R = query(ql, qr, m+1, r, id<<1|1);
    if (L.first == R.first) {
        L.second += R.second;
    }
    return max(L, R);
}

void update(int ql, int qr, int val, int l = 0, int r = n-1, int id = 1) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        tree[id].tag += val;
        return;
    }
    push(id);
    int m = (l + r) / 2;
    update(ql, qr, val, l, m, id<<1);
    update(ql, qr, val, m+1, r, id<<1|1);
    pull(id);
}

void build_tree(int l = 0, int r = n-1, int id = 1) {
    if (l == r) {
        tree[id] = make_node(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build_tree(l, m, id<<1);
    build_tree(m+1, r, id<<1|1);
    pull(id);
}

signed main() {
    int q, act, l, r, v;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build_tree();
    while (q--) {
        cin >> act >> l >> r;
        if (act == 1) {
            cin >> v;
            update(l-1, r-1, v);
        } else {
            p ans = query(l-1, r-1);
            cout << ans.first << " " << ans.second << endl;
        }
    }
}
