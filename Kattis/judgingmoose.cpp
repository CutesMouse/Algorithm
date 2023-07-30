#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
    int l,r;
    cin >> l >> r;
    if (l == r && r == 0) {
        cout << "Not a moose";
    } else if (l == r) {
        cout << "Even " << (l+r);
    } else {
        cout << "Odd " << max(l, r) * 2;
    }
    return 0;
}
