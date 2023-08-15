#include <iostream>

using namespace std;


int main() {
    bool event[366] = {false};
    int N;
    cin >> N;
    int s, t;
    while (N--) {
        cin >> s >> t;
        for (int j = s; j <= t; j++) event[j] = true;
    }
    int d = 0;
    for (int i = 1; i <= 365; i++) {
        d += event[i];
    }
    cout << d;
}
