#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int C[3];
int main() {
    int N, ans = 10000;
    cin >> N >> C[0] >> C[1] >> C[2];
    sort(C,C+3);
    for (int a = 0; a < 10000; a++) {
        int c0 = a * C[0];
        if (c0 > N) break;
        for (int b = 0; b < 10000; b++) {
            int coins = c0 + b * C[1];
            if (coins > N) break;
            if ((N - coins) % C[2] == 0) {
                ans = min(ans,a + b+ ((N-coins)/C[2]));
            }
        }
    }
    cout << ans << endl;
}
