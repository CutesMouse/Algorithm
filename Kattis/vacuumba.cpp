#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.141592653

using namespace std;

int main() {
    int n, k;
    cin >> n;
    while (n--) {
        cin >> k;
        double facing = 90;
        double x = 0;
        double y = 0;
        double turn, dis;
        while (k--) {
            cin >> turn >> dis;
            facing += turn;
            x += cos(PI * facing / 180) * dis;
            y += sin(PI * facing / 180) * dis;
        }
        cout << fixed << setprecision(6);
        cout << x << " " << y << endl;
    }
}
