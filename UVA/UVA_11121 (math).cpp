#include <iostream>
using namespace std;

void prt_2base(long long int n) {
    if (n == 0) {
        cout << 0;
        return;
    }
    int tp = __lg(n);
    for (int i = tp; i >= 0; i--) {
        cout << ("%d", n >> i & 1);
    }
}

int main() {
    long long int mask = 0;
    for (int i = 0; i < 16; i++) {
        mask = ((mask << 1) | 1) << 1;
    }
    long long int k;
    int c = 1;
    int n;
    cin >> n;
    while(n--) {
        cin >> k;
        cout << "Case #" << (c++) << ": ";
        prt_2base((mask + k) ^ mask);
        cout << endl;
    }
}
