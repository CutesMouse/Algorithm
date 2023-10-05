#include <iostream>
using namespace std;

int main() {
    long long int a, b, c, d;
    cout << "Please enter first line of the matrix: ";
    cin >> a >> b;
    cout << "Please enter second line of the matrix: ";
    cin >> c >> d;
    long long int det = a * d - b * c;
    cout << "The determinant of the input matrix is: ";
    cout << det << endl;
    if (det) cout << "The matrix is nonsingular.";
    else cout << "The matrix is singular.";

}
