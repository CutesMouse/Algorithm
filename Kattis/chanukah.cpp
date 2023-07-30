#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() {
    int N, n, K;
    cin >> N;
    while (N--) {
        cin >> n >> K;
        cout << n << " " << ((K+1) * K) / 2 + K;
        cout << endl;
    }
}
