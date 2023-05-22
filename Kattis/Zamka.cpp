#include <iostream>
using namespace std;

int main() {
    int L, D, X;
    cin >> L >> D >> X;
    for (int i = L; i <= D; i++) {
        int s = 0;
        int cpy_i = i;
        while (cpy_i > 0) {
            s += cpy_i % 10;
            cpy_i /= 10;
        }
        if (s == X) {
            cout << i << endl;
            break;
        }
    }

    for (int i = D; i >= L; i--) {
        int s = 0;
        int cpy_i = i;
        while (cpy_i > 0) {
            s += cpy_i % 10;
            cpy_i /= 10;
        }
        if (s == X) {
            cout << i << endl;
            break;
        }
    }
}
