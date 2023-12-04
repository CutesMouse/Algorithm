#include <iostream>
#define MOD 1000000007
using namespace std;

long long int m(long long int a, long long int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long int add(long long int a, long long int b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

long long int half(long long int a, long long int b) {
    if (a % 2) b /= 2;
    else a /= 2;
    return m(a, b);
}

int main() {
    /*long long int k;
    cin >> k;
    for (long long int i = 1; i <= k; i++) {
        long long int to = (k/(k/i));
        cout << i <<": " << k / i << " (predict " << i << "~"<<(k/(k/i)) <<") -> " << k / to <<endl;
        i = to;
    }*/
    long long int k;
    long long int ans = 0;
    cin >> k;
    long long int ptr = k, from = 1, to;
    while (ptr) {
        to = (k / ptr);
        //long long int tmp = ans;
        ans = add(ans, m(ptr, half(from + to, to - from + 1)));
        //if (ans < 0) cout << tmp << ", " << m(ptr, (from + to) * (to - from + 1) / 2) << ", " << ans <<endl;
        //cout <<ans << endl;
        from = to+1;
        ptr = (k / (from));
    }
    cout << ans % MOD;
}
