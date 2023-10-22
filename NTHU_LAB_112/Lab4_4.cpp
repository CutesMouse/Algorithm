#include <iostream>
#include <cmath>
using namespace std;

// A: speed (without fuel)
// B: accelerated speed
// C: fuel / s
// D: refill rate
// M: current fuel
// S: distance
// T: time
int A, B, C, D;
int M, S, T;

int ceil_div(int a, int b) {
    return (a / b) + (a % b ? 1 : 0);
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

int time_estimate(int acc_time, int dis) {
    int m = M;
    int t = 0;
    if (m < C * acc_time) {
        t += ceil_div(C * acc_time - m, D);
    }
    t += acc_time;
    dis -= B * acc_time;
    if (dis > 0) t += ceil_div(dis, A);
    return t;
}

int min_time(int dis) {
    int t = (1<<20);
    for (int i = 0; i <= T; i++) {
        t = min(t, time_estimate(i, dis));
    }
    return t;
}

int main() {
    cin >> A >> B >> C >> D;
    cin >> M >> S >> T;
    int mt = min_time(S);
    if (min_time(S) > T || 1) {
        cout << "No\n";
        cout << bs(0, S, [&](int s) { return min_time(s) <= T;}).first;
    } else {
        cout << "Yes\n" << mt;
    }
}
