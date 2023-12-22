#include <iostream>
#define MAXN 1005
#define int long long int
using namespace std;

int n;

//2D-BIT
int lowbit(int x) {
    return (-x) & x;
}

class BIT {
public:
    int bit[MAXN] = {0};
    void modify(int p, int val) {
        for (; p <= n; p += lowbit(p)) {
            bit[p] += val;
        }
    }
    int query(int p) {
        int s = 0;
        for (; p; p -= lowbit(p)) {
            s += bit[p];
        }
        return s;
    }
};

class BIT2D {
public:
    BIT bit[MAXN];
    void modify(int x, int y, int val) {
        for (; x <= n; x += lowbit(x)) {
            bit[x].modify(y, val);
        }
    }
    int query(int x, int y) {
        int s = 0;
        for (; x; x -= lowbit(x)) {
            s += bit[x].query(y);
        }
        return s;
    }
};

BIT2D bit;

int state_at(int x, int y) {
    return bit.query(x, y) - bit.query(x-1, y) - bit.query(x, y-1) + bit.query(x-1, y-1);
}

int range_sum(int x1, int y1, int x2, int y2) {
    return bit.query(x2, y2) - bit.query(x2, y1-1) - bit.query(x1-1, y2) + bit.query(x1-1, y1-1);
}

signed main() {
    int q, a, b, c, d, e;
    cin >> n >> q;
    cin.get();
    string line;
    for (int r = 0; r < n; r++) {
        getline(cin, line);
        for (int c = 0; c < n; c++) {
            bit.modify(r+1, c+1, line[c] == '*');
        }
    }
    while (q--) {
        cin >> a >> b>> c;
        if (a == 1) {
            int offset = (state_at(b, c) == 1) * (-2) + 1;
            bit.modify(b, c, offset);
        } else {
            cin >> d >> e;
            cout << range_sum(b, c, d, e) << endl;
        }
    }
}
