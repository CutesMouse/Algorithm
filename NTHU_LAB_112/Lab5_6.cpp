#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

ll ps[1000001];

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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        ll p = 0;
        cin >> n;
        ps[0] = 0;
        vector<int> stk;
        vector<int> mx_stk;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> k;
            p += k;
            ps[i+1] = p;
        }
        for (int i = 0; i < n+1; i++) {
            while (stk.size() && ps[stk.back()] > ps[i]) stk.pop_back();
            while (mx_stk.size() && ps[mx_stk.back()] <= ps[i]) mx_stk.pop_back();
            int mx = mx_stk.size() ? mx_stk.back() : -1;
            stk.emplace_back(i);
            mx_stk.emplace_back(i);
            ans = max(ans, i - stk[bs(0, (int) stk.size()-2, [&](int k) { return stk[k] <= mx; }).second]);
        }
        cout << ans << endl;
    }
}
