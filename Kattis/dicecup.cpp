#include <iostream>

using namespace std;

int main() {
    int odd[405] = {0};
    int m,n;
    cin >> m >> n;
    int mx = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            odd[(i+1)+(j+1)]++;
            mx = max(odd[(i+1)+(j+1)], mx);
        }
    }

    for (int i = 1; i <= (m+n); i++) {
        if (odd[i] == mx) cout << i << endl;
    }
}
