#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<pair<double, double> > v;

int main() {
    double mx = 0;
    int N;
    cin >> N;
    double x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.emplace_back(x, y);
    }
    for (int p1 = 0; p1 < N; p1++) {
        for (int p2 = p1 + 1; p2 < N; p2++) {
            for (int p3 = p2 + 1; p3 < N; p3++) {
                mx = max(abs(v[p1].first * v[p2].second + v[p2].first * v[p3].second + v[p1].second * v[p3].first
                             - v[p2].first * v[p1].second - v[p3].first * v[p2].second - v[p1].first * v[p3].second), mx);
            }
        }
    }
    cout << fixed << setprecision(6) << 0.5*mx;
}
