#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#define MAXN 200000
#define int long long int
using namespace std;

// ST, RWD
vector<pair<int, int>> event[4*MAXN];
// to be relabel
vector<tuple<int, int, int>> events;
set<int> nums;

void relabel() {
    vector<int> label = {nums.begin(), nums.end()};
    for (auto [st, ed, rwd] : events) {
        st = lower_bound(label.begin(), label.end(), st) - label.begin();
        ed = lower_bound(label.begin(), label.end(), ed) - label.begin();
        event[ed].emplace_back(st, rwd);
    }
}

int n;

int tree[8 * MAXN] = {0};

void pull(int id) {
    tree[id] = max(tree[id<<1], tree[id<<1|1]);
}

int query(int ql, int qr, int l = 0, int r = nums.size()-1, int id = 1) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[id];
    int m = (l + r) / 2;
    return max(query(ql, qr, l, m, id<<1), query(ql, qr, m+1, r, id<<1|1));
}

void update(int p, int val, int l = 0, int r = nums.size()-1, int id = 1) {
    if (p > r || p < l) return;
    if (l == r) {
        tree[id] = val;
        return;
    }
    int m = (l + r) / 2;
    update(p, val, l, m, id<<1);
    update(p, val, m+1, r, id<<1|1);
    pull(id);
}

signed main() {
    cin >> n;
    int st, ed, rwd;
    for (int i = 0; i < n; i++) {
        cin >> st >> ed >> rwd;
        events.emplace_back(st, ed, rwd);
        nums.emplace(st);
        nums.emplace(ed);
    }
    relabel();

    /*for (int i = 0; i < nums.size(); i++) {
        for (auto [st, rwd] : event[i]) {
            printf("event st: %d, ed: %d, rwd: %d\n", st, i, rwd);
        }
    }*/

    for (int i = 0; i < nums.size(); i++) {
        int val = 0;
        for (auto [st, rwd] : event[i]) {
            val = max(val, query(0, st-1) + rwd);
        }
        update(i, val);
    }
    cout << tree[1];
}
