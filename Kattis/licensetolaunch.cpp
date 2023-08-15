#include <iostream>

using namespace std;

int main() {
    int n, j;
    cin >> n;
    int mx_value = -1;
    int mx_index = -1;
    for (int i = 0; i < n; i++) {
        cin >> j;
        if (j < mx_value || mx_value == -1) {
            mx_value = j;
            mx_index = i;
        }
    }
    cout << mx_index;
}
