#include <iostream>
using namespace std;


void move_disk(int n, int A, int B, int C) {
    if (n < 0) return;
    move_disk(n-1, A, C, B);
    cout << A << " " << C << endl;
    move_disk(n-1, B, A, C);
}

int p(int j) {
    int i = 1;
    while (j--) i *= 2;
    return i;
}

int main() {
    int n;
    cin >> n;
    cout << p(n) - 1 << endl;
    move_disk(n-1, 1, 2, 3);
}
