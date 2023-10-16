#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

pair<long long int, int> ary[5005];
long long int n, x;

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
    for (int i = 0; i < n; i++) {
        cin >> ary[i].first;
        ary[i].second = i+1;
    }
    ary[n].first = x;
    sort(ary, ary+n);
    for (int a = 0; a < n; a++) {
        for (int b = a+1; b < n; b++) {
            long long int s = x - ary[a].first - ary[b].first;
            auto gap = (bs(1ll+b, n, [&](long long int a) {
                return ary[a].first < s;
            }));
            if (ary[gap.second].first == s) {
                cout << ary[a].second << " " << ary[b].second << " " << ary[gap.second].second;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
