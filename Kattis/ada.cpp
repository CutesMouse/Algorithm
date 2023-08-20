#include <iostream>
using namespace std;

bool same(int *ary, int n) {
    int last = ary[0];
    for (int i = 1; i < n; i++) {
        if (ary[i] != last) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int diff[100][100];
    for (int i = 0; i < n; i++) cin >> diff[0][i];
    int times = 0;
    int base = n;
    while (!same(diff[times], base)) {
        times++;
        for (int i = 1; i < base; i++) diff[times][i-1] = diff[times-1][i] - diff[times-1][i-1];
        base--;
    }
    diff[times][base] = diff[times][0];
    base++;
    cout << times << " ";
    for (int i = times-1; i >= 0; i--) {
        diff[i][base] = diff[i][base-1] + diff[i+1][base-1];
        base++;
    }
    cout << diff[0][n];
}
