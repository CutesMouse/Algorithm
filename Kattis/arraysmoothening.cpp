#include <iostream>
#include <queue>
#include <map>

using namespace std;

map<int, int> times;

int required_K(int mx) {
    int k = 0;
    for (auto [element, t] : times) {
        k += max(0, t - mx);
    }
    return k;
}

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
    int N, K, a;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a;
        times[a]++;
    }
    //for (int i = 0; i < N; i++) cout << required_K(i) << endl;
    cout << bs(0, N, [&](int mx_val) { return required_K(mx_val) > K;}).second;
}
