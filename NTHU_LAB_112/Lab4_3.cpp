#include <iostream>
using namespace std;

template<class Ty, class FuncTy>
pair<Ty, Ty> bs(Ty left, Ty right, FuncTy check) {
    if (check(right)) return {right,right+1};
    if (!check(left)) return {left-1, left};
    while (left + 1 < right) {
        Ty mid = left + (right - left) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    return {left, right};
}

int n;
long long int k;
long long int ary[200005];

//return group amount
int groups(long long int mxs) {
    int g = 0;
    long long int temp = 0;
    for (int i = 0; i < n; i++) {
            temp += ary[i];
        if (temp > mxs) {
            temp = ary[i];
            g++;
        }
    }
    if (temp) g++;
    return g;
}

int main() {
    cin >> n >> k;
    long long int upper = 0;
    long long int lower = 0;
    for (int i = 0; i < n; i++) {
        cin >> ary[i];
        upper += ary[i];
        lower = max(lower, ary[i]);
    }
    cout << bs(lower, upper, [&](long long int g) { return groups(g) > k;}).second;
}
