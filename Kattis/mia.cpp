#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void mia(int x0, int x1, int r0, int r1) {
    int big_1 = 0, big_2 = 0;
    int x = max(x0, x1) * 10 + min(x0, x1);
    int r = max(r0, r1) * 10 + min(r0, r1);
    int win = -1;
    if (x == r) {
        cout << "Tie.\n";
        return;
    }
    if (x == 21) win = 0;
    else if (r == 21) win = 1;
    else if (x0 == x1 && r0 != r1) win = 0;
    else if (x0 != x1 && r0 == r1) win = 1;
    else win = r > x;

    cout << "Player " << (win+1) << " wins.\n";
}


int main() {
    int x0, x1, r0, r1;
    while (cin >> x0 >> x1 >> r0 >> r1) {
        if (x0 == 0 && x1 == 0 && r0 == 0 && r1 == 0) return 0;
        mia(x0, x1, r0, r1);
    }
    return 0;
}
