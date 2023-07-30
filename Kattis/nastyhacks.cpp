#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int A, B, C;
        cin >> A >> B >> C;
        int prof = B - C - A;
        if (prof > 0) cout << "advertise\n";
        else if (prof == 0) cout << "does not matter\n";
        else cout << "do not advertise\n";
    }
}
