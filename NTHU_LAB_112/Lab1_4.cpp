#include <iostream>
#include <set>
using namespace std;

int w[26] = {0};
string s;
string p;
set<string> l;

void dfs(int depth) {
    if (depth == s.size()) {
        l.emplace(p);
    }
    for (int i = 0; i < 26; i++) {
        if (!w[i]) continue;
        w[i]--;
        p[depth] = 'a' + i;
        dfs(depth+1);
        w[i]++;
    }
}

int main() {
    cin >> s;
    p.resize(s.size());
    for (int i = 0; i < s.size(); i++) {
        w[s[i]-'a']++;
    }
    dfs(0);
    cout << l.size() << endl;
    for (string k : l) cout << k << endl;
}
