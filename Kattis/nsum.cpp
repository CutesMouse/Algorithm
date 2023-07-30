#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int S = 0;
    int n;
    cin >> N;
    while (N--) {
        cin >> n;
        S += n;
    }
    cout << S;
}
