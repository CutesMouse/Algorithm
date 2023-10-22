#include <iostream>
#include <algorithm>
using namespace std;

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
    int n, k, p;
    int scores[100000];
    int leaderboard[100000];
    cin >> n >> k;
    for (int i = 0; i <n; i++) {
        int t = 0;
        for (int j = 0; j < 3; j++) {
            cin >> p;
            t += p;
        }
        scores[i] = t + 300;
        leaderboard[i] = t;
    }
    sort(leaderboard, leaderboard + n, greater<int>());
    for (int i = 0; i < n; i++) {
        if (bs(0, n-1, [&](int r) { return leaderboard[r] > scores[i]; }).second <= k) cout << "Yes\n";
        else cout << "No\n";
    }
}
