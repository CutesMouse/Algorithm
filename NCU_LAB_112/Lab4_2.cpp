#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int pos = 1;
    double a = 1, b = 1;
    int c = 1;
    char d = 'y';
    while (1) {
        do {
            if (a <= 0) cout << "Wrong input!!! Please enter again!!!\n";
            cout << "Please enter the resistivity (Ohm meter): ";
            cin >> a;
        } while (a <= 0);
        do {
            if (b <= 0) cout << "Wrong input!!! Please enter again!!!\n";
            cout << "Please enter the cross-sectional area (mm^2): ";
            cin >> b;
        } while (b <= 0);
        do {
            if (c <= 0) cout << "Wrong input!!! Please enter again!!!\n";
            cout << "Please enter the wire length (m): ";
            cin >> c;
        } while (c <= 0);
        cout << pos++ << ". The wire resistance is " << fixed << setprecision(3) << a / b * c << "(Ohm).\n";
        do {
            if (d != 'y' && d != 'n') cout << "Wrong input!!! Please enter again!!!\n";
            cout << "Do you still want to analyze the experimental result? (y/n) ";
            cin >> d;
        } while (d != 'y' && d != 'n');
        if (d == 'n') break;
    }
    cout << "Bye~~~";
}
