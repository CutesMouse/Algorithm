#include <iostream>
#include <cmath>
using namespace std;

// count from right hand side, 0-based
int get_digit(int n, int pos) {
    int base = pow(10, pos);
    return (n / base) % 10;
}

// Bubble sort
void sort_by_digit(int *arr, int size, int pos) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1; j++) {
            if (get_digit(*(arr+j), pos) > get_digit(*(arr+j+1), pos)) swap(*(arr+j), *(arr+j+1));
        }
    }
}

int main() {
    int num[8], digits = 1;
    for (int i = 0; i < 8; i++) {
        cin >> *(num + i);
        digits = max(digits, (int) floor(log10(*(num+i))+1));
    }
    for (int i = 0; i < digits; i++) {
        if (i == 0) cout << "Sort by rightmost digit:\n";
        else if (i == digits - 1) cout << "Sort by leftmost digit:\n";
        else cout << "Sort by next digit:\n";
        sort_by_digit(num, 8, i);
        for (int i = 0; i < 8; i++) {
            if (i) cout << ", ";
            cout << *(num + i);
        }
        cout << endl << endl;
    }
}
