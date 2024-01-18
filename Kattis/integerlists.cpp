#include <iostream>
#define maxn 100001
using namespace std;

int a[maxn];

void parseList(string lis) {
    int buffer = 0;
    int ptr = 0;
    for (int i = 1; i < lis.size(); i++) {
        char c = lis[i];
        if (c >= '0' && c <= '9') {
            buffer = 10 * buffer + (c - '0');
        } else {
            a[ptr++] = buffer;
            buffer = 0;
        }
    }
}

int main() {
    int t, n;
    string act, lis;
    cin >> t;
    getline(cin, act);
    while (t--) {
        getline(cin, act);
        cin >> n;
        getline(cin, lis);
        getline(cin, lis);
        parseList(lis);
        int st = 0, ed = n-1;
        bool frt = true;
        for (auto a : act) {
            if (a == 'R') frt = !frt;
            else {
                if (frt) st++;
                else ed--;
            }
        }
        if (st - 1 == ed) cout << "[]\n";
        else if (st > ed) cout << "error\n";
        else {
            if (frt) {
                for (int i = st; i <= ed; i++) cout << (i == st ? "[" : ",") << a[i];
                cout << "]\n";
            } else {
                for (int i = ed; i >= st; i--) cout << (i == ed ? "[" : ",") << a[i];
                cout << "]\n";
            }
        }
    }
}
