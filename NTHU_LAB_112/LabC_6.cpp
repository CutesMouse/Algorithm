#include <iostream>
#define MAXN 200000
#define int long long int
using namespace std;

int n;

struct Node {
    int data;
    int set_tag;
    int add_tag;
};

class Seg {
public:
    Node tree[4*MAXN] = {0};

    int get_val(int l, int r, int id) {
        if (tree[id].set_tag) return (r - l + 1) * (tree[id].set_tag + tree[id].add_tag);
        return (r - l + 1) * (tree[id].add_tag) + tree[id].data;
    }

    void push(int l, int r, int id) {
        tree[id].data = get_val(l, r, id);
        if (tree[id].set_tag) {
            tree[id<<1].set_tag = tree[id<<1|1].set_tag = (tree[id].set_tag + tree[id].add_tag);
            tree[id].set_tag = tree[id].add_tag = 0;
            tree[id<<1].add_tag = tree[id<<1|1].add_tag = 0;
            return;
        }
        tree[id<<1].add_tag += tree[id].add_tag;
        tree[id<<1|1].add_tag += tree[id].add_tag;
        tree[id].add_tag = 0;
        //printf("id: %d, tag: %d, [%d-%d], data%d\n", id<<1, tree[id<<1].tag, l, r, tree[id<<1].data);
    }

    void pull(int l, int r, int id) {
        int m = (l + r) / 2;
        tree[id].data = get_val(l, m, id<<1) + get_val(m+1, r, id<<1|1);
    }

    void build_tree(int* a, int l = 0, int r = n-1, int id = 1) {
        if (l == r) {
            tree[id].data = a[l];
            return;
        }
        int m = (l + r) / 2;
        build_tree(a, l, m, id<<1);
        build_tree(a, m+1, r, id<<1|1);
        pull(l, r, id);
    }

    int query(int ql, int qr, int l = 0, int r = n-1, int id = 1) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return get_val(l, r, id);
        push(l, r, id);
        int m = (l + r) / 2;
        return query(ql, qr, l, m, id<<1) + query(ql, qr, m+1, r, id<<1|1);
    }
    void range_set(int ql, int qr, int val, int l = 0, int r = n-1, int id = 1) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[id].set_tag = val;
            tree[id].add_tag = 0;
            return;
        }
        push(l, r, id);
        int m = (l + r) / 2;
        range_set(ql, qr, val, l, m, id<<1);
        range_set(ql, qr, val, m+1, r, id<<1|1);
        pull(l, r, id);
    }
    void range_add(int ql, int qr, int val, int l = 0, int r = n-1, int id = 1) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[id].add_tag += val;
            return;
        }
        push(l, r, id);
        int m = (l + r) / 2;
        range_add(ql, qr, val, l, m, id<<1);
        range_add(ql, qr, val, m+1, r, id<<1|1);
        pull(l, r, id);
    }
};

Seg seg;

signed main() {
    int q;
    int t[MAXN];
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> t[i];
    seg.build_tree(t);
    int act, a, b, x;
    while (q--) {
        cin >> act >> a >> b;
        if (act == 1) {
            cin >> x;
            seg.range_add(a-1, b-1, x);
        } else if (act == 2) {
            cin >> x;
            seg.range_set(a-1, b-1, x);
        } else {
            cout << seg.query(a-1, b-1) << endl;
        }
    }
}
