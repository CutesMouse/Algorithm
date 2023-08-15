#include <iostream>

using namespace std;


int main() {
    int g = 0, e = 0;
    int p;
    for (int i = 0; i < 4; i++) {
        cin >> p;
        g += p;
    }
    for (int i = 0; i < 4; i++) {
        cin >> p;
        e += p;
    }
    if (g > e) cout << "Gunnar";
    else if (g == e) cout << "Tie";
    else cout << "Emma";
}
