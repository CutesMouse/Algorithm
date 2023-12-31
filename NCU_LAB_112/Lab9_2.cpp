#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// both st and ed are closed interval
bool match(string &s, int st, int ed) {
    int num = (ed - st + 1);
    if (num <= 2) return false;
    if (num % 2) return false;
    for (int i = 0; i < num/2; i++) {
        if (s[st + i] != s[ed - i]) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    vector<string> amt;
    for (int len = s.size(); len >= 2; len--) {
        for (int st = 0; (st+len) <= s.size(); st++) {
            if (!match(s, st, st + len - 1)) continue;
            string str = s.substr(st, len);
            if (count(amt.begin(), amt.end(), str)) continue;
            amt.push_back(str);
        }
    }
    for (auto iter = amt.begin(); iter != amt.end(); iter++) cout << *iter << endl;
    if (amt.empty()) cout << "No mirror-repeat subsequence is found.";
}
