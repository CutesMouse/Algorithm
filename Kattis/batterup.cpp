#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, k;
    int sum = 0;
    int base = 0;

    cin >> n;
    while(n--) {
        cin >> k;
        if (k != -1) {
            sum += k;
            base++;
        }
    }
    cout << (double) sum / base;
}
