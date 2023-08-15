#include <iostream>

using namespace std;


int main() {
    int r, n, k;
    cin >> r >> n;
    bool used[101] = {0};
    for (int i = 0; i < n; i++) {
        cin >> k;
        used[k] = true;
    }
    bool found = false;
    for (int i = 1; i <= r; i++) {
        if (!used[i]) {
            found = true;
            cout << i;
            break;
        }
    }
    if (!found) cout << "too late";
}
