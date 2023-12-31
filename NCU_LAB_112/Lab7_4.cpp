#include <iostream>
using namespace std;

int dp[100][100] = {0};

int pascal(int r, int c) {
    if (r == 1 || r == 2) return 1;
    if (c == 1 || c == r) return 1;
    if (dp[r][c]) return dp[r][c];
    return dp[r][c] = (pascal(r-1, c-1) + pascal(r-1, c));
}

int main() {
    int N;
    cout << "Input the number of row N: ";
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < (i+1); j++) {
            cout << pascal(i+1, j+1) << " ";
        }
        cout << "\n";
    }
}
