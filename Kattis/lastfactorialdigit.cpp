#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int fac = 1;
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            fac *= i;
            fac %= 10;
        }
        cout << fac << endl;
    }
}
