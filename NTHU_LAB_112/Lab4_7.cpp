#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int ll;

template<class Ty, class FuncTy>
pair<Ty, Ty> bs(Ty L, Ty R, FuncTy check) {
    if (check(L) == false) return {L-1, L};
    if (check(R) == true) return {R, R+1};
    while (L + 1 < R) {
        Ty mid = L + (R - L) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    return {L, R};
}

int n, k;
ll a[10000];
ll b[10000];
ll c[10000];

int win_groups(int day) {
    ll d[10000];
    for (int i = 0; i < n; i++) {
        d[i] = a[i] + b[i] * day;
    }
    sort(d, d+n);
    int w = 0;
    int last = -1;
    for (int i = 0; i < n; i++) {
        last = bs(last+1, n-1, [&](int k) {
            return d[k] <= c[i];
        }).second;
        if (last == n) break;
        w++;
        if (last == n-1) break;
    }
    return w;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        sort(c, c+n);
        int ans = bs(0, 100000000, [&](int day) {
            return win_groups(day) < k;
        }).second;
        if (ans == 100000001) cout << "-1\n";
        else cout << ans << "\n";
    }
}
