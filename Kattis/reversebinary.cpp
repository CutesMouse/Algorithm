#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    int nw = 0;
    cin >> n;
    while (n > 0) {
        nw *= 2;
        nw += n%2;
        n/=2;
    }
    cout << nw;
}
