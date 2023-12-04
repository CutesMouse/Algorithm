#include <iostream>
#define int long long int
using namespace std;

// extgcd(x, p)
// 結果的xp表示x的模反元素
pair<int, int> extgcd(int a, int b) {
    if (b == 0) return {1, 0};
    auto [xp, yp] = extgcd(b, a % b);
    return {yp, xp - a / b * yp};
}

int mod_inverse(int x, int p) {
    return (extgcd(x, p).first + p)% p;
}

signed main() {
    int n;
    cin >> n;
    int r[3];
    int k[3];
    while (n--) {
        for (int i = 0; i < 3; i++) cin >> k[i] >> r[i];
        int M = k[0] * k[1] * k[2];
        int ans = 0;
        for (int i = 0; i < 3; i++) ans += (mod_inverse(M/k[i], k[i]) * M/k[i] * r[i]);
        cout << ans%M << endl;
    }
}
