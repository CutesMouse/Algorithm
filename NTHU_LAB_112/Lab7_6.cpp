#include <iostream>
#define MOD 1000000007
using namespace std;

typedef long long int ll;

pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0) return {1, 0};
    auto [xp, yp] = extgcd(b, a % b);
    return {yp, xp - a / b * yp};
}

ll mod_inverse(ll x, ll p = MOD) {
    return (extgcd(x, p).first + p)% p;
}

ll m(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll d(ll a, ll b) {
    return ((a % MOD) * mod_inverse(b)) % MOD;
}

ll factorial[1000001];

int main() {
    factorial[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        factorial[i] = m(factorial[i-1], i);
    }
    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        //cout <<factorial[a] <<endl;
        cout << d(factorial[a], m(factorial[b], factorial[a-b])) << endl;
    }
}
