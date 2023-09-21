#include <iostream>
using namespace std;

bool ring[10];
int n;

int get_move() {
    for (int i = 0; i < n-1; i++) {
        if (ring[i]) return i+1;
    }
    return -1;
}

void prt(int k) {
    string s = (ring[k] ? "in" : "out");
    cout << "Move ring "<< k+1 << " " << s << endl;
}

void A() {
    ring[0] = !ring[0];
    prt(0);
}

void B() {
    int m = get_move();
    ring[m] = !ring[m];
    prt(m);
}

bool ok() {
    for (int i = 0; i < n; i++) {
        if (ring[i]) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n;i ++) ring[i] = true;
    bool s = n%2;
    while (!ok()) {
        if (s) A();
        else B();
        s = !s;
    }
}
