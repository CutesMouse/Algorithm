#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int pts[2] = {0, 0};
    int s2[2] = {0, 0};
    string s;
    cin >> s;
    for (int i = 0; i < s.size()/2; i++) {
        pts[s[2*i]-'A'] += (s[2*i+1]-'0');
        s2[s[2*i]-'A'] += (s[2*i+1] == 2);
    }
    if (pts[0] == pts[1] && pts[0] == 10) {
        if (s2[0] > s2[1]) cout << "A";
        else cout << "B";
    }
    else if (pts[0] > pts[1]) {
        cout << "A";
    }
    else cout << "B";
}
