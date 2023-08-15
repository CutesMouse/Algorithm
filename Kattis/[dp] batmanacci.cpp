#include <iostream>
using namespace std;

long long int dp[100];

char getCh(int n, long long int k) {
    if (n == 1) return 'N';
    if (n == 2) return 'A';
    if (k > dp[n-2]) return getCh(n-1, k - dp[n-2]);
    return getCh(n-2, k);
}

int main() {
	int n;
    long long int k;
	cin >> n >> k;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 92; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    if (n % 2) n = 91;
    else n = 92;
    cout << getCh(n, k);
}
