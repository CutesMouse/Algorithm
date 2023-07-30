#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != -1) {
        bool linked[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> linked[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            bool weak = true;
            for (int j = 0; j < n; j++) {
                if (!linked[i][j]) continue;
                for (int k = 0; k < n; k++) {
                    if (linked[i][k] && linked[j][k]) weak = false;
                }
            }
            if (weak) cout << i << " ";
        }
        cout << endl;
    }
}
