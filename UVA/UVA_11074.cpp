#include <iostream>
using namespace std;

int main() {
    int S, T, N;
    int counter = 1;
    while (cin >> S >> T >> N) {
        if (!S && !T && !N) break;
        cout << "Case " << counter++ << ":\n";
        int w = T * (N+1) + S * N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < T ; j++) {
                for (int k = 0; k < w ;k++) cout << "*";
                cout << endl;
            }
            for (int s = 0; s < S; s++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < T; k++) cout << "*";
                    for (int k = 0; k < S; k++) cout << ".";
                }
                for (int k = 0; k < T; k++) cout << "*";
                cout << endl;
            }
        }
        for (int j = 0; j < T ; j++) {
            for (int k = 0; k < w ;k++) cout << "*";
            cout << endl;
        }
        cout << endl;
    }
}
