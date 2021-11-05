#include <iostream>
#include <cstring>
using namespace std;
long long int d[51][2];
long long int dp(int n, int last) {
    if (n == 0) return 1;
    if (d[n][last]) return d[n][last];
    long long int amount = dp(n-1,0);
    if (last == 0) amount += dp(n-1,1);
    d[n][last] = amount;
    return amount;
}
int main() {
    int n;
    cin >> n;
    memset(d,0,sizeof(d));
    int r;
    for (int p = 0; p < n ; p++) {
        cin >> r;
        printf("Scenario #%d:\n%lld\n\n",p+1,dp(r,0));
    }
}
