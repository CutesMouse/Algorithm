#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int N, A, B, L;
    cin >> N >> A >> B;
    float mx = sqrt(A*A + B*B);
    while(N--) {
        cin >> L;
        if (L > mx) cout << "NE\n";
        else cout << "DA\n";
    }
}
