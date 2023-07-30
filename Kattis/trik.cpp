#include <iostream>
#include <cmath>

using namespace std;

int main() {
    bool A = true;
    bool B = false;
    bool C = false;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        switch (c) {
            case 'A':
                swap(A, B);
                break;
            case 'B':
                swap(B, C);
                break;
            case 'C':
                swap(A, C);
                break;
        }
    }
    if (A) cout << 1;
    if (B) cout << 2;
    if (C) cout << 3;

}
