#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    bool inc = true;
    bool dec = true;
    int N;
    string s;
    cin >> N;
    bool first = true;
    string last;
    while (N--) {
        cin >> s;
        if (first) {
            first = false;
            last = s;
            continue;
        }
        inc = inc && (last < s);
        dec = dec && (last > s);
        last = s;
    }
    if (inc) cout << "INCREASING";
    else if (dec) cout << "DECREASING";
    else cout << "NEITHER";
}
