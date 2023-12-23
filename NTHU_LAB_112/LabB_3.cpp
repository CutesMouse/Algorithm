#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define MAXN (200000)
using namespace std;

int timeline[MAXN] = {0};
// first: endtime, second: starttime
vector<pair<int, int>> movies;
set<int> times;
int tree_range;

void relabel() {
    vector<int> vt = {times.begin(), times.end()};
    for (auto &[ed, st] : movies) {
        ed = lower_bound(vt.begin(), vt.end(), ed) - vt.begin();
        st = lower_bound(vt.begin(), vt.end(), st) - vt.begin();
        tree_range = max(tree_range, ed);
    }
}

int n;

int tree[8*MAXN] = {0};
int tag[8*MAXN] = {0};

int get_val(int id) {
    return tree[id] + tag[id];
}

void push(int id) {
    tree[id] = get_val(id);
    tag[id<<1] += tag[id];
    tag[id<<1|1] += tag[id];
    tag[id] = 0;
}

void pull(int id) {
    tree[id] = max(get_val(id<<1), get_val(id<<1|1));
}


int query(int ql, int qr, int l = 0, int r = tree_range-1, int id = 1) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return get_val(id);
    push(id);
    int m = (l + r) / 2;
    return max(query(ql, qr, l, m, id<<1), query(ql, qr, m+1, r, id<<1|1));
}
void range_add(int ql, int qr, int val, int l = 0, int r = tree_range-1, int id = 1) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        tag[id] += val;
        return;
    }
    push(id);
    int m = (l + r) / 2;
    range_add(ql, qr, val, l, m, id<<1);
    range_add(ql, qr, val, m+1, r, id<<1|1);
    pull(id);
}

int main() {
    int k, a, b;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        times.emplace(a);
        times.emplace(b);
        movies.emplace_back(b, a);
    }
    relabel();
    int ans = 0;
    sort(movies.begin(), movies.end());
    for (auto [ed, st] : movies) {
        //cout << st << ", " <<ed << endl;
        if (query(st, ed-1) < k) {
            range_add(st, ed-1, 1);
            //printf("add 1 on the range [%d, %d]\n", st, ed-1);
            //printf("now the max on the range [%d, %d] is %d\n", st, ed-1, query(st, ed-1));
            ans++;
        }
    }
    cout << ans;
}
