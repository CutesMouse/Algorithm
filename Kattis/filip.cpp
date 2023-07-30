#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    int rA=0, rB=0;
    for (int i = 0; i < 3; i++) {
        rA += A % 10;
        rB += B % 10;
        rA *= 10;
        rB *= 10;
        A /= 10;
        B /= 10;
    }
    cout << max(rA, rB) / 10;


}
