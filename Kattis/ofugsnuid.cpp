#include <iostream>

using namespace std;

int main() {
    int k[100000];
    int n;
    cin >> n;
    for (int i = n-1; i >= 0; i--) {
        cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        cout << k[i] << endl;
    }
}
