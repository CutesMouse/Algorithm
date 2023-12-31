#include <iostream>
using namespace std;

int getVal(char c) {
    switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
    }
    return 0;
}

int main() {
    char c;
    cout << "Roman numeral 1: ";
    int v1 = 0;
    int v2 = 0;
    int last = -1;
    while ((c = cin.get()) != '\n') {
        int tmp = getVal(c);
        if (last != -1 && tmp > last) {
            v1 -= (last * 2);
            v1 += tmp;
            last = -1;
            continue;
        }
        v1 += tmp;
        last = tmp;
    }
    cout << "Roman numeral 2: ";
    last = -1;
    while ((c = cin.get()) != '\n') {
        int tmp = getVal(c);
        if (last != -1 && tmp > last) {
            v2 -= (last * 2);
            v2 += tmp;
            last = -1;
            continue;
        }
        v2 += tmp;
        last = tmp;
    }
    cout << "Operation(+/-): ";
    cin >> c;
    if (c == '+') cout << "Calculated result: " << v1+v2;
    else cout << "Calculated result: " << v1 - v2;

}
