#include <iostream>
using namespace std;

long long int fast_pow(long long int a, long long int b, long long int MOD) {
    long long int ans = 1;
    while (b) {
        if (b & 1) ans = a * ans % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans % MOD;
}

int main() {
    int n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        cout << fast_pow(a, fast_pow(b, c, 1e9+6), 1e9+7) << endl;
    }
}
