#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        bool appear[3000] = {false};
        int last, current;
        cin >> last;
        for (int i = 1; i < n; i++) {
            cin >> current;
            appear[abs(last - current)] = true;
            last = current;
        }
        bool jolly = true;
        for (int i = 1; i <= n - 1; i++) {
            jolly = jolly && appear[i];
        }
        if (!jolly) cout << "Not jolly";
        else cout << "Jolly";
        cout << endl;
    }

    return 0;
}
