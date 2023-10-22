#include <iostream>
using namespace std;

void find_binary(int n) {
    if (n == 1) {
        cout << 1;
        return;
    }
    find_binary(n/2);
    cout << n % 2;
}

int main() {
    int n;
    cout << "Please enter a decimal number or -1 to exit: ";
    while (cin >> n && n != -1) {
        cout << "The binary representation of "<< n << " is ";
        find_binary(n);
        cout << ".\n\n";
        cout << "Please enter a decimal number or -1 to exit: ";
    }
    cout << "Goodbye~";
}
