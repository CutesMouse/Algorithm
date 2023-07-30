#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int *loadAtom(string &formula) {
    int *atom = new int[26];
    memset(atom, 0, sizeof(int) * 26);
    int target = -1;
    int cnt = 0;
    for (int i = 0; i < formula.size(); i++) {
        char c = formula[i];
        if (c >= 'A' && c <= 'Z') {
            if (target != -1) {
                atom[target] += max(cnt, 1);
            }
            target = c - 'A';
            cnt = 0;
        } else {
            cnt *= 10;
            cnt += formula[i] - '0';
        }
    }
    if (target != -1) {
        atom[target] += max(cnt, 1);
    }
    return atom;
}

int chem(string &formula1, int k, string &formula2) {
    int i;
    int* a1 = loadAtom(formula1);
    int* a2 = loadAtom(formula2);

    int amount = -1;

    for (i = 0; i < 26; i++) {
        if (a2[i] == 0) continue;
        int na = a1[i] * ((int)k) / a2[i];
        if (amount == -1 || na < amount) amount = na;
    }
    return amount;
}

int main() {
    int k;
    string formula1, formula2;
    cin >> formula1;
    cin >> k;
    cin >> formula2;
    cout << chem(formula1, k, formula2);
    return 0;
}
