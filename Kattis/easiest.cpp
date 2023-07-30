#include <iostream>

using namespace std;

int sum(int n) {
    int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main() {
    int N, i;
    while (cin >> N && N) {
        int s = sum(N);
        for (i = 11; i <= 100; i++) {
            if (s == sum(N * i)) break;
        }
        cout << i << endl;
    }
}
