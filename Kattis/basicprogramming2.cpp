#include <iostream>
#include <algorithm>
#include <map>
#define maxn 200001
using namespace std;

int N, t;
int a[maxn];
map<int, int> times;

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

void act_1() {
    for (int i = 0; i < N; i++) {
        int L = 7777 - a[i];
        int R_idx = bs(i+1, N-1, [&](int idx) {
            return a[idx] < L;
        }).second;
        if (R_idx == N || a[R_idx] != L) continue;
        cout << "Yes";
        return;
    }
    cout << "No";
}

void cnt() {
    for (int i = 0; i < N; i++) {
        times[a[i]]++;
    }
}

void act_2() {
    cnt();
    for (auto [val, t] : times) {
        if (t >= 2) {
            cout << "Contains duplicate";
            return;
        }
    }
    cout << "Unique";
}

void act_3() {
    cnt();
    for (auto [val, t] : times) {
        if (t > N/2) {
            cout << val;
            return;
        }
    }
    cout << -1;
}

void act_4() {
    if (N % 2 == 0) {
        cout << a[N/2-1] << " " << a[N/2];
    } else cout << a[N / 2];
}

void act_5() {
    int ptr = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] >= 100 && a[i] <= 999) {
            a[ptr++] = a[i];
        }
    }
    for (int i = 0; i < ptr; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    cin >> N >> t;
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);
    switch(t) {
        case 1:
            act_1();
            break;
        case 2:
            act_2();
            break;
        case 3:
            act_3();
            break;
        case 4:
            act_4();
            break;
        case 5:
            act_5();
            break;
    }
}
