#include <iostream>
#include <vector>
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

int main() {
    int n, k;
    cin >> n >> k;
    ll nums[n + k - 1];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<pair<ll, int>> stk;
    for (int i = 0; i < (n+k-1); i++) {
        while (stk.size() && stk.back().first <= nums[i%n]) stk.pop_back();
        stk.emplace_back(nums[i%n], i);
        if (i < k-1) continue;
        cout << stk[bs(0, (int) stk.size() - 2, [&](int a) { return stk[a].second < (i - k + 1);}).second].first << " ";
    }
}
