#include <iostream>
using namespace std;

int main() {
    int L = 0, R = 0, M = 0;
    int amt = 0;
    string line;
    for (int j = 0; j < 8; j++) {
        getline(cin, line);
        int inner_amt = 0;
        L = L << 1;
        R = R >> 1;
        int S = L | R | M;
        for (int i = 0; i < 8; i++) {
            if (line[i] == '*') {
                inner_amt++;
                amt++;
                if (S & (1 << i)) amt = 10;
                L = L | (1<<i);
                R = R | (1<<i);
                M = M | (1<<i);
            }
        }
        if (inner_amt >= 2) amt = 10;
    }
    if (amt == 8) cout << "valid";
    else cout << "invalid";
}
