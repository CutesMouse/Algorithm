#include <iostream>

using namespace std;

int main() {
    int N;
    cout << "Please input positive integer: ";
    cin >> N;
    int ps[20];
    int index = 0;
    int ptr = 2;
    while (N != 1) {
        if (N%ptr) {
            ptr++;
            continue;
        }
        N /= ptr;
        ps[index++] = ptr;
    }
    bool first = true;
    for (int i = 0; i < index; i++) {
        int n = ps[i];
        if (!first) cout << "*";
        first = false;
        cout << n;
    }
}
