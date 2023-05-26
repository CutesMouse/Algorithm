#include <iostream>

using namespace std;

int main() {
    int n, f, A, N, L;
    cin >> n;
    while (n--) {
        cin >> f;
        int prize = 0;
        for (int i = 0; i < f; i++) {
            cin >> A >> N >> L;
            prize += A * L;
        }
        cout << prize << endl;
    }
    return 0;
}
