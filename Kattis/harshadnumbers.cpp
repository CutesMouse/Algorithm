#include <iostream>

using namespace std;

bool is_match(int n) {
    int cpy = n;
    int sum = 0;
    while (cpy > 0) {
        sum += cpy % 10;
        cpy /= 10;
    }
    return !(n % sum);
}

int main() {
    int n;
    cin >> n;
    while (!is_match(n)) n++;
    cout << n;
}
