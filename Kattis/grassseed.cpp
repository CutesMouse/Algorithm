#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double C, W, H;
    int L;
    double cost = 0;
    cin >> C >> L;
    while (L--) {
        cin >> W >> H;
        cost += C * W * H;
    }
    cout << fixed << setprecision(7) << cost;
}
