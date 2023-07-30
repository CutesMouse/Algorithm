#include <iostream>

using namespace std;

bool possible(int a, int b, int c) {
    return (a + b == c) || (a - b == c) || (a * b == c) || (a / b == c && a % b == 0);
}

int main() {
    int n;
    cin >> n;
    int a, b, c;
    while (n--) {
        cin >> a >> b >> c;
        if (possible(a, b, c) || possible(b, a, c)) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}
