#include <iostream>
using namespace std;
int main() {
    cout << "Please enter a number N: \n";
    int n;
    cin >> n;
    for (int i = 1; i<= n; i++) {
        switch (i%15) {
        case 0:
            cout << "hakuna-matata";
            break;
        case 3:
        case 6:
        case 9:
        case 12:
            cout << "hakuna";
            break;
        case 5:
        case 10:
            cout << "matata";
            break;
        default:
            cout << i;
        }
        cout << " ";
    }
}
