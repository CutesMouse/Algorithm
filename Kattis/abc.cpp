#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int num[3];
    for (int i = 0; i < 3; i++) cin >> num[i];
    sort(num, num+3);
    string list;
    cin >> list;
    for (int i = 0; i < 3; i++) {
        cout << num[list[i] - 'A'] << " ";
    }
}
