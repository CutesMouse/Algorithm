#include <iostream>

using namespace std;

int main() {
    int n, k;
    int s = 0;
    cin >> n;
    while (n--) {
        cin >> k;
        if (k < 0) s -= k;
    }
    cout << s;
}
