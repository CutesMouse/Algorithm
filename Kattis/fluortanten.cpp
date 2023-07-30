#include <iostream>

using namespace std;

int n;
int list[1000000];

int main() {
    cin >> n;
    long long int s = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> list[i];
        if (list[i] == 0) cin >> list[i];
        s += (i+1) * list[i];
    }
    long long int l = 0;
    long long int s2 = 0;
    for (int i = (n-1) ; i >= 0; i--) {
        s2 += list[i];
        l = max(l, s2);
    }
    cout << (s+l);
}
