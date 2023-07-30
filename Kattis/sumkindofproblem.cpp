#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int S1, S2, S3;
    int P, K, N;
    cin >> P;
    while (P--) {
        cin >> K >> N;
        S1 = S2 = S3 = 0;
        cout << K << " ";
        for (int i = 0; i < N; i++) {
            S1 += (i+1);
            S2 += (2*i+1);
            S3 += (2*i+2);
        }
        cout << S1 << " " << S2 << " " << S3 << endl;
    }
}
