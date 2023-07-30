#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int nc = (a*a - (a-b)*(a-b));
    cout << fixed << setprecision(10);
    double p = ((double) nc / (a*a));
    cout << 100-(p*100);
}
