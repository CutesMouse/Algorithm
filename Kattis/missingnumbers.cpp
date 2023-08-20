#include <iostream>
using namespace std;

int main() {
    int n, k;
    bool good = true;
    int last = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int i = (last+1); i < k; i++) {
            cout << i << endl;
            good = false;
        }
        last = k;
    }
    if (good) cout << "good job";
}
