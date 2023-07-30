#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a == b && a == 0) return 0;
        cout << (a/b) << " " << (a%b) << " / " << b << endl;
    }
}
