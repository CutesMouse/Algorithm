#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int st;
    int m = 1;
    int d = 0;
    cin >> st;
    while (m < st) {
        d++;
        m *= 2;
    }
    cout << (d+1);
}
