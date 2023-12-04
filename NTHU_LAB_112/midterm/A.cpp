#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long int px[200000];
long long int bar[200000];
long long int K;

template<class Ty, class FuncTy>
pair<int, int> bs(Ty left, Ty right, FuncTy check) {
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
    cin >> N >> K;
    long long int temp = 0;
    for (int i = 0; i < N; i++) {
        cin >> bar[i];
    }
    sort(bar, bar+N, greater<int>());
    px[0] = bar[0];
    for (int i = 1; i < N; i++) {
        px[i] = bar[i] + px[i-1];
        //cout << px[i] << endl;
    }
    auto r = bs(0, N-1, [&](int i) { return px[i] < K;});
    if (r.second == N) cout << -1;
    else cout << r.second+1;
}
