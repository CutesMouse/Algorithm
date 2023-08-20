#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int list1[5000];
    int list2[5000];
    int list1_copy[5000];

    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> list1[i];
            list1_copy[i] = list1[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> list2[i];
        }
        sort(list1, list1+n);
        sort(list2, list2+n);
        for (int i = 0; i < n; i++) {
            cout << *(find(list1, list1+n, list1_copy[i]) - list1 + list2) << endl;
        }
        cout << endl;
    }
}
