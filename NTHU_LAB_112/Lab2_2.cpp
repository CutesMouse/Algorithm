#include <iostream>
#include <set>
#include <string>
using namespace std;
int t, n;
set<string> ans;
int num[12];
int selected[12];

void print(int k) {
    string r;
    for (int i = 0; i < k; i++) {
        if (i) r = r + '+';
        r = r + to_string(selected[i]);
    }
    ans.emplace(r);
}

void dfs(int depth, int sum, int selecting) {
    if (depth == n) {
        if (sum) return;
        print(selecting);
        return;
    }
    if (sum < 0) return;
    dfs(depth+1, sum, selecting);
    selected[selecting] = num[depth];
    dfs(depth+1, sum-num[depth], selecting+1);
}

int main() {
    while (cin >> t >> n && n) {
        ans.clear();
        for (int i = 0; i < n; i++) cin >> num[i];
        cout << "Sums of " << t << ":\n";
        dfs(0, t, 0);
        for (auto iter = ans.rbegin(); iter != ans.rend(); iter++) {
            cout << *iter << endl;
        }
        if (ans.empty()) cout << "NONE\n";
    }
}
