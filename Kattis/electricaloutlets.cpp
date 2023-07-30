#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n;
    while (n--) {
        int s = 0;
        cin >> m;
        while (m--) {
            cin >> k;
            s += (k-1);
        }
        cout << s + 1 << endl;
    }
}
