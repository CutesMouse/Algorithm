#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define int long long int
using namespace std;

int ceil(int k, int m) {
    bool offset = (k % m);
    return offset + k / m;
}

int c[100001];
int n, m;

bool can_max_within(int mx) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        cost += ceil(c[i], mx);
    }
    return cost <= m;
}

template<class Ty, class FuncTy>
pair<Ty, Ty> bs(Ty L, Ty R, FuncTy check) {
    if (check(L) == 1) return {L-1, L};
    if (check(R) == 0) return {R, R+1};
    while (L + 1 < R) {
        Ty mid = L + (R - L) / 2;
        if (check(mid)) R = mid;
        else L = mid;
    }
    return {L, R};
}

signed main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> c[i];
    cout << bs(1, 1000000000, can_max_within).second;
}
