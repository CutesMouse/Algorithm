#include <iostream>
#include <cstring>
using namespace std;
int ns[205];
int main() {
    ns[1] = 1;
    int x = 0;
    cin >> x;
    for (int i = 2; i <= x; i++) {
        ns[i] = ns[i-1] + i*i - i + 1;
    }
    cout << ns[x];
}
