#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define maxn 2001
using namespace std;

int w[maxn];
int v[maxn];

int dp[maxn][maxn];
int from[maxn];

int main() {
    int n, c;
    while (cin >> c >> n) {
        for (int i = 0; i < n; i++) {
            cin >> v[i] >> w[i];
        }
        memset(dp, 0, sizeof dp);
        from[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= c; j++) {
                dp[i][j] = dp[i-1][j];
                if (i - w[j] >= 0) {
                    if (dp[i-w[j]] + v[j] > dp[i]) {
                        dp[i] = dp[i - w[j]] + v[j];
                        from[i] = j;
                        //cout << i << " " <<from[i] << endl;
                    }
                }
                //cout << i << " " <<w[j] << endl;
            }
        }
        vector<int> knap;
        //int mx_val = max_element(dp, dp + c + 1) - dp;
        //cout << from[mx_val] << endl;
        while (mx_val) {
            //cout <<mx_val <<endl;
            knap.emplace_back(from[mx_val]);
            mx_val = mx_val - w[from[mx_val]];
        }
        cout << knap.size() << endl;
        for (auto iter = knap.rbegin(); iter != knap.rend(); iter++) cout << *iter << " ";
        cout <<endl;
    }
}
