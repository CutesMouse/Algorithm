#include <iostream>
#define MAXN 200000
#define int long long int
using namespace std;

int lowbit(int x) {
    return x & -x;
}

int n;

class BIT {
public:
    int bit[MAXN+2] = {0};

    int query(int p) {
        int s = 0;
        for (; p; p -= lowbit(p)) {
            s += bit[p];
        }
        return s;
    }

    void add_modify(int p, int val) {
        for (; p <= n; p += lowbit(p)) {
            bit[p] += val;
        }
    }
};

BIT D, xD;

void add_range(int a, int b, int val) {
    D.add_modify(a, val);
    xD.add_modify(a, a * val);
    if (b < n) {
        D.add_modify(b+1, -val);
        xD.add_modify(b+1, -(b+1) * val);
    }
}


int query(int p) {
    return (p+1) * (D.query(p)) - xD.query(p);
}

signed main() {
    int q, a, b, c, d;
    int m[MAXN];
    cin >> n >> q;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        D.add_modify(i, m[i] - last);
        xD.add_modify(i, i * (m[i] - last));
        last = m[i];
        //cout <<"Q: " << query(i) << endl;
    }
    while (q--) {
        cin >> a >> b;
        //cout << "A: " << a << endl;
        if (a == 1) {
            cin >> c >> d;
            add_range(b, c, d);
        } else {
            cout << query(b) - query(b-1) << endl;
        }
    }
}
