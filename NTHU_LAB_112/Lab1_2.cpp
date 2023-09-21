#include <iostream>
using namespace std;

bool ring[20];
int n;

int get_move() {
    for (int i = 0; i < n-1; i++) {
        if (ring[i]) return i+1;
    }
    return -1;
}

int p(int n) {
    int i = 1;
    while (n--) i *= 2;
    return i;
}

void prt() {
    for (int i = 0; i < n; i++) {
        cout << ring[n - i - 1];
    }
    cout << endl;
}

void A() {
    ring[0] = !ring[0];
    prt();
}

void B() {
    int m = get_move();
    ring[m] = !ring[m];
    prt();
}

int main() {
    cin >> n;
    for (int i = 0; i < n;i ++) ring[i] = false;
    prt();
    bool s = true;
    for (int i = 1; i < p(n); i++) {
        if (s) A();
        else B();
        s = !s;
    }
}
