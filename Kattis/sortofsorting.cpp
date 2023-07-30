#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a, string b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}
int main()
{
    int n;
    string item[205];
    while (cin >> n) {
        if (!n) return 0;
        for (int i = 0; i < n;i ++) cin >> item[i];
        stable_sort(item, item+n, cmp);
        for (int i = 0; i < n; i++) cout << item[i] << endl;
        cout << endl;
    }
}
