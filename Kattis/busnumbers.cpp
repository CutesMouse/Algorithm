#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int bus[1000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> bus[i];
    }
    sort(bus, bus+N);
    for (int i = 0; i < N; ) {
        int b = bus[i];
        int j = 1;
        for (j = 1; (j+i) < N; j++) {
            if (bus[i+j] != (b+j)) break;
        }
        if (j > 2) {
            cout << b << "-" << b+j-1 << " ";
            i += j;
        }
        else {
            cout << b << " ";
            i++;
        }
    }
}
