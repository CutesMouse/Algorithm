#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double d;
    cin >> d;
    cout << fixed << setprecision(0);
    cout << d * 1000 * 5280 / 4854.0;
}
