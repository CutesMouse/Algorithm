#include <iostream>
using namespace std;

int dp[3001][3001] = {0};
pair<int, int> from[3001][3001];
string a, b;

int main() {
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (dp[i][j+1] > dp[i+1][j]) {
                dp[i+1][j+1] = dp[i][j+1];
                from[i+1][j+1] = {i, j+1};
            } else {
                dp[i+1][j+1] = dp[i+1][j];
                from[i+1][j+1] = {i+1, j};
            }

            if (a[i] == b[j]) {
                dp[i+1][j+1] = dp[i][j] + 1;
                from[i+1][j+1] = {i, j};
            }
        }
    }
    int x = a.size();
    int y = b.size();
    //cout << from[0][12].first << from[0][12].second << endl;
    //cout << from[0][25].first << from[0][25].second << endl;
    //return 0;
    string ans;
    while (x && y) {
        //cout << x << " " << y << endl;
        //if (a[x] == b[y]) ans.push_back(a[x]);
        int nx = from[x][y].first;
        int ny = from[x][y].second;
        if (x - nx && y - ny) ans.push_back(a[x-1]);
        x = nx;
        y = ny;
    }
    //if (ans.size() < dp[a.size()-1][b.size()-1]) ans.push_back(a[0]);
    cout << string(ans.rbegin(), ans.rend());
}
