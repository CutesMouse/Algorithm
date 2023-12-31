#include <iostream>
using namespace std;

int main() {
    int mr, mc;
    cout << "Please enter the size of the input matrix: \n";
    cin >> mr >> mc;
    double mtx[mr][mc];
    cout << "Please input the matrix: \n";
    for (int r = 0; r < mr; r++) {
        for (int c = 0; c < mc ;c++) {
            cin >> mtx[r][c];
        }
    }
    for (int c = 0; c < mc; c++) {
        for (int r = 0; r < mr; r++) {
            cout << mtx[r][c] << " ";
        }
        cout << endl;
    }
}
