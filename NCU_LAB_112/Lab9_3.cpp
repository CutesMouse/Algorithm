#include <iostream>
using namespace std;

// reverse the number when loaded
string readNumber(string &a, string &b, string &c) {
    string ans = a;
    ans += b[1];
    ans += b[0];
    ans += c[1];
    ans += c[0];
    return ans;
}

int toDecimal(string &num) {
    int ans = 0;
    for (int i = 0; i < num.size(); i++) {
        ans *= 2;
        ans += (num[i] - '0');
    }
    return ans;
}

int main() {
    string a, b, c;
    bool upper_case = true;
    while (cin >> a >> b >> c) {
        string num = readNumber(a, b, c);
        int dec = toDecimal(num);
        if (dec >= 6 && dec <= 31) {
            char k = 'z' - (dec - 6);
            if (upper_case) k += ('A' - 'a');
            cout << k;
            upper_case = false;
        }
        if (dec == 0) cout << ' ';
        if (dec == 1) cout << ',';
        if (dec == 2) {
            cout << '.';
            upper_case = true;
        }
        if (dec == 3) {
            cout << '!';
            upper_case = true;
        }
        if (dec == 4) {
            cout << '?';
            upper_case = true;
        }
        if (dec == 5) cout << '-';
    }
}
