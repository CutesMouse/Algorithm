#include <iostream>

using namespace std;

int drink = 0;

int main() {
    int a, b, c;
    int bottle;
    cin >> a >> b >> c;
    bottle = a + b;
    while (bottle >= c) {
        drink += bottle / c;
        bottle = (bottle / c) + (bottle % c);
    }
    cout << drink;
}
