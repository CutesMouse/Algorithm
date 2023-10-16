#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please enter the length of isosceles triangle: ";
    while (cin >> n) {
        if (n >= 1) break;
        cout << "Please enter the length of isosceles triangle: ";
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - 1 - i); j++) {
            cout << " ";
        }
        for (int j = 0; j < i+1; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
