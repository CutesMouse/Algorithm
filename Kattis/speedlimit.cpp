#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == -1) return 0;
        int last = 0;
        int tot = 0;
        int s, t;
        for (int i = 0; i < n; i++) {
            cin >> s >> t;
            tot += (t-last) * s;
            last = t;
        }
        cout << tot << " miles\n";
    }
}
