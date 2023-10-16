#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, a;
    cin >> n;
    long long int ns[n];
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> ns[i] >> a;
        sum += a;
    }
    sort(ns, ns+n);
    for (int i = 0; i < n; i++) {
        sum -= ns[i] * (n-i);
    }
    cout << sum;
}
