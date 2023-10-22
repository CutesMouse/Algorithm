#include <iostream>
#include <queue>
#define RIGHT 0
#define DOWN 1
using namespace std;

typedef long long int ll;

ll k;
int n, m;
typedef pair<ll, bool> step;
priority_queue<step, vector<step>, greater<step>> ppq;
const int dr[2] = {0, 1};
const int dc[2] = {1, 0};
bool A = RIGHT;
pair<ll, ll> pA = {1, 1};
bool B = DOWN;
pair<ll, ll> pB = {1, 1};
ll red = 0, blue = 0, purple = 0;

ll overlap(ll t) {
    if (A == B) {
        if (pA.first == pB.first && pA.second == pB.second) return t;
        return 0;
    }
    if (A == RIGHT) {
        ll pA_f = pA.second + t;
        if (pB.second <= pA.second || pB.second > pA_f) return 0;
        ll pB_f = pB.first + t;
        if (pA.first <= pB.first || pA.first > pB_f) return 0;
        return 1;
    }
    ll pA_f = pA.first + t;
    if (pB.first <= pA.first || pB.first > pA_f) return 0;
    ll pB_f = pB.second + t;
    if (pA.second <= pB.second || pA.second > pB_f) return 0;
    return 1;
}

int main() {
    cin >> k;
    cin >> n >> m;
    ll tmp;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        ppq.emplace(tmp, 0);
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        ppq.emplace(tmp, 1);
    }
    ppq.emplace(k+1, 0);
    ll last = 1;
    while (ppq.size()) {
        ll t = ppq.top().first;
        bool turn = ppq.top().second;
        ppq.pop();
        ll lap = overlap(t - last);
        purple += lap;
        red += (t - last - lap);
        blue += (t - last - lap);
        pA.first += dr[A] * (t - last);
        pA.second += dc[A] * (t - last);
        pB.first += dr[B] * (t - last);
        pB.second += dc[B] * (t - last);
        last = t;
        if (turn) B = !B;
        else A = !A;
    }
    cout << red << " " << blue << " " << purple;
}
