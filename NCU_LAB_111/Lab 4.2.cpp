#include <iostream>
using namespace std;
int main()
{
    cout << "Please enter the length of equilateral triangle: ";
    int n;
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < (n-i); j++) cout << " ";
        for (int j = 0; j < i; j++) cout << "*";
        cout << endl;
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < (n-i); j++) cout << " ";
        for (int j = 0; j < i; j++) cout << "*";
        cout << endl;
    }
}

