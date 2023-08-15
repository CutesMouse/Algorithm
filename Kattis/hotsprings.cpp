#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t[n];
    for (int i = 0; i < n; i++) cin >> t[i];
    sort(t, t+n);
    int ptr = n / 2;
    int left = ptr - 1;
    int right = ptr + 1;
    bool next_left = false;
    cout << t[ptr] << " ";
    while (left >= 0 || right < n) {
        next_left = !next_left;
        if (next_left) {
            cout << t[left] << " ";
            left--;
        } else {
            cout << t[right] << " ";
            right++;
        }
    }
}
