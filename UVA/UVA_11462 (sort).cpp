#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    char numbers[2000005];
    while (cin >> n) {
        if (!n) return 0;
        for (int i = 0; i < n; i++) {
            short int temp;
            cin >> temp;
            numbers[i] = (char) temp;
        }
        sort(numbers,numbers+n);
        for (int i = 0; i <n; i++) cout << (i != 0 ? " ": "") << (short int) numbers[i];
        cout << endl;
    }
}
