#include <iostream>
using namespace std;

int main() {
    int N, A, F;
    cin >> N;
    while (N--) {
        cin >> A >> F;
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < A; j++) {
                for (int k = 0; k < j+1; k++) {
                    cout << (j+1);
                }
                cout << endl;
            }
            for (int j = A-2; j >= 0; j--) {
                for (int k = 0; k < j+1; k++) {
                    cout << (j+1);
                }
                cout << endl;
            }
            if (N!=0 || i != F-1) cout << endl;
        }
    }
}
