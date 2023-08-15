#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k, n, last, c;
    cin >> k;
    while (k--) {
        cin >> n;
        cin >> last;
        for (int i = 1; i < n; i++) {
            cin >> c;
            if (c-last != 1) {
                cout << i+1 << endl;
                continue;
            }
            last = c;
        }
    }
}
