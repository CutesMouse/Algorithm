#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int l = 0;
    int c;
    int NC = N;
    while (NC--) {
        cin >> c;
        l += c;
    }
    cout << (l - N + 1);
}
