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
    int W, N, a, b;
    cin >> W >> N;
    int area = 0;
    while (N--) {
        cin >> a >> b;
        area += a*b;
    }
    cout << area / W;
}
