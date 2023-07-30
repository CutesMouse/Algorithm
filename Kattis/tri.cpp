#include <iostream>
#include <algorithm>

using namespace std;

bool is_add(int a, int b, int c) {
    if (a + b == c) {
        cout << a << "+" << b << "=" << c;
        return true;
    }
    return false;
}

bool is_minus(int a, int b, int c) {
    if (a - b == c) {
        cout << a << "-" << b << "=" << c;
        return true;
    }
    return false;
}

bool is_multi(int a, int b, int c) {
    if (a * b == c) {
        cout << a << "*" << b << "=" << c;
        return true;
    }
    return false;
}

bool is_div(int a, int b, int c) {
    if (a / b == c) {
        cout << a << "/" << b << "=" << c;
        return true;
    }
    return false;
}

bool is_radd(int a, int b, int c) {
    if (a == b + c) {
        cout << a << "=" << b << "+" << c;
        return true;
    }
    return false;
}

bool is_rminus(int a, int b, int c) {
    if (a == b - c) {
        cout << a << "=" << b << "-" << c;
        return true;
    }
    return false;
}

bool is_rmulti(int a, int b, int c) {
    if (a == b * c) {
        cout << a << "=" << b << "*" << c;
        return true;
    }
    return false;
}

bool is_rdiv(int a, int b, int c) {
    if (a == b / c) {
        cout << a << "=" << b << "/" << c;
        return true;
    }
    return false;
}

int main() {
    int t[3];
    cin >> t[0] >> t[1] >> t[2];
    if (is_add(t[0], t[1], t[2])) return 0;
    if (is_minus(t[0], t[1], t[2])) return 0;
    if (is_multi(t[0], t[1], t[2])) return 0;
    if (is_div(t[0], t[1], t[2])) return 0;
    if (is_radd(t[0], t[1], t[2])) return 0;
    if (is_rminus(t[0], t[1], t[2])) return 0;
    if (is_rmulti(t[0], t[1], t[2])) return 0;
    if (is_rdiv(t[0], t[1], t[2])) return 0;
}
