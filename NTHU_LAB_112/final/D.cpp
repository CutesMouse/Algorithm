#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define int long long int
#define maxn 2000001
using namespace std;

vector<int> primes;
//bool not_prime[maxn] = {false};
int LPFs[maxn] = {0};
int ans[maxn] = {0};
int facts[20] = {0};

void list_primes(int n) {
    for (int i = 2; i < n; i++) {
        if (!LPFs[i]) {
            primes.emplace_back(i);
            LPFs[i] = i;
        }
        for (auto p : primes) {
            if (p * i > n) break;
            LPFs[i * p] = p;
            if (i % p == 0) break;
        }
    }
}

int solve(int k) {
    if (ans[k]) return ans[k];
    int index = -1;
    int K = k;
    int last = -1;
    int lpf = LPFs[k];
    while (k > 1) {
        if (last == lpf) facts[index]++;
        else {
            facts[++index] = 1;
            last = lpf;
        }
        k /= lpf;
        lpf = LPFs[k];
    }
    int s = 1;
    for (int i = 0; i <= index; i++) {
        s *= (1 + 3 * (2 * facts[i] + facts[i] * (facts[i]-1)));
    }
    return ans[K] = s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, k;
    list_primes(maxn);
    cin >> t;
    ans[1] = 1;
    while (t--) {
        cin >> k;
        //auto v = expand(factorization(K));
        //for (auto i : v) cout << i << endl;
        cout << solve(k) << "\n";
    }
}
