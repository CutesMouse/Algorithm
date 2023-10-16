#include <iostream>
#include <algorithm>
using namespace std;

// prx[n]: a[0] + a[1] + .. + a[n-1]
pair<long long int, int> prx[200005];
long long int n, x;

long long int ans = 0;

template <class Ty, class FuncTy>
pair<Ty, Ty> bs(Ty left, Ty right, FuncTy check) {
    if (check(left) == false) return {left-1, left};
    if (check(right) == true) return {right, right+1};
    while (right - left > 1) {
        Ty mid = left + (right - left) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    return {left, right};
}

int main() {
    cin >> n >> x;
    long long int ps = 0;
    long long int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        prx[i] = {ps, i};
        ps = ps + tmp;
    }
    prx[n] = {ps, n};
    sort(prx, prx+n+1);
    for (int i = 0; i < n; i++) {
        long long int s = x + prx[i].first;
        int idx;
        auto f = bs(i+1ll, n, [&](long long int a) { return prx[a].first < s || (prx[a].first == s && prx[a].second <= prx[i].second);});
        auto e = bs(i+1ll, n, [&](long long int a) { return prx[a].first <= s;});
        ans += e.second - f.second;
    }
    cout << ans;
}
