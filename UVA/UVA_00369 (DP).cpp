#include <iostream>
#include <cstring>
using namespace std;
long int d[10000][10000];
long int dp(int m, int n) {
    if (m == n) return 1;
    if (m < n) return 0;
    if (d[m][n]) return d[m][n];
    if (m == 0) {
        return 0;
    }
    if (n == 1) {
        d[m][n] = m;
        return m;
    }
    long int p = dp(m-1,n) + dp(m-1,n-1);
    d[m][n] = p;
    return p;
}
int main() {
    int m,n;
    memset(d,0,sizeof(d));
    while (cin >> m >> n) {
        if (m == 0 || n == 0) return 0;
        printf("%d things taken %d at a time is %li exactly.\n",m,n,dp(m,n));
    }
}
