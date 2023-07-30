#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, b;
    double p;
    cin >> N;
    cout << fixed << setprecision(4);
    while (N--) {
        cin >> b >> p;
        double t_mx = p / (b - 1);
        double t_mn = p / (b + 1);
        cout << (60 / t_mx) << " " << (60 * b / p) << " " << (60 / t_mn) << endl;
    }
}
