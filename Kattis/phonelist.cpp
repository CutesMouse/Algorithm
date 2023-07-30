#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t, n;
    string list[10000];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> list[i];
        }
        sort(list, list+n);
        bool consis = true;
        for (int i = 1; i < n; i++) {
            int l = min(list[i].size(), list[i-1].size());
            consis = consis && (list[i].substr(0, l) != list[i-1].substr(0, l));
        }
        if (consis) cout << "YES\n";
        else cout << "NO\n";
    }
}
