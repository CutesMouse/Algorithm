#include <iostream>

using namespace std;

int main() {
    float A[2][2];
    cout << "Please input the array element for A[0][0] A[0][1] A[1][0] A[1][1]: ";
    cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];
    float det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    cout << "det(A) is: "<<det <<"\n";
    if (det != 0) cout << "The inverse matrix of A exists.";
    else cout << "The inverse matrix of A doesn't exist.";
}
