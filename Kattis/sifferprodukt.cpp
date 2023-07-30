#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    while (x >= 10) {
        int product = 1;
        int cpy_x = x;
        while (cpy_x > 0) {
            if (cpy_x % 10 != 0) product *= cpy_x % 10;
            cpy_x /= 10;
        }
        x = product;
    }
    cout << x;
}
