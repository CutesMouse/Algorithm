#include <iostream>
#define int long long int
#define MAXN 200000
using namespace std;

int a[MAXN+1], b[MAXN+1];
int n;

int tree[4*MAXN+4] = {0};

void pull(int l, int r, int id) {
    tree[id] = max(tree[id<<1], tree[id<<1|1]);
}

void modify(int p, int val, int l = 0, int r = n-1, int id = 1) {
    if (p < l || p > r) return;
    if (l == r) {
        tree[id] = val;
        return;
    }
    int m = (l + r) / 2;
    modify(p, val, l, m, id<<1);
    modify(p, val, m+1, r, id<<1|1);
    pull(l, r, id);
}

int query(int ql, int qr, int l = 0, int r = n-1, int id = 1) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[id];
    int m = (l + r) / 2;
    return max(query(ql, qr, l, m, id<<1), query(ql, qr, m+1, r, id<<1|1));
}

signed main() {
    int h;
    cin >> n;
    a[0] = b[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> h;
        a[h] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    for (int h = 1; h <= n; h++) {
        int val = query(0, a[h]-1) + b[a[h]];
        modify(a[h]-1, val);
        /*for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) continue;
            dp[i] = max(dp[i], dp[j] + b[i]);
        }
        ans = max(ans, dp[i]);*/
    }
    cout << tree[1];
}
