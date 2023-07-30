#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // n = 1 4*4-4-4+1
    // n = 2 9*4-4-4-4+1
    int n;
    cin >> n;
    int sq = pow(2, n);
    cout << (sq+1) * (sq+1);
}
