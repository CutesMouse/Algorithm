#include <iostream>
#include <cstring>
#define int long long int
#define INF (1<<29)
using namespace std;

int n;
int a[5005];
int px[5005];

signed main() {
    //freopen("testcase.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cout <<"test";
    cin >> n;
    px[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        px[i+1] = px[i] + a[i];
    }
    int dp[2][5005];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -INF;
        }
    }
    for (int i = 0; i < 2; i++) {
        dp[i][i] = a[i];
    }
    for (int i = n-2; i >= 0; i--) {
        //cout << i <<endl;
        dp[i&1][i] = a[i];
        for (int j = i+1; j < n; j++) {
            //cout << i << " " << j <<endl;
            //printf("dp[%d][%d]\n", i % 2, j);
            //if (j > 4990 || i > 4990 || i < 5 || j < 5) cout << i << ", " << j <<endl;
            dp[i&1][j] = max(px[j + 1] - px[i] - dp[!(i&1)][j], px[j + 1] - px[i] - dp[i&1][j-1]);
        }
    }
    cout << dp[0][n-1];
}
