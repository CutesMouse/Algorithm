#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int n, t;
int city[5][5] = {0};

vector<int> ofce(5);
vector<int> mx_ofce;
vector<int> list;
int mn_dis = 999999999;
int m = 0;

int dis() {
    int d = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            int mn = 99999999;
            for (int &a : ofce) {
                mn = min(mn, city[r][c] * (abs(a/5 - r) + abs(a%5 - c)));
            }
            d += mn;
        }
    }
    return d;
}

void dfs(int depth) {
    if (m == 5) {
        int d = dis();
        if (d < mn_dis) {
            mn_dis = d;
            mx_ofce = ofce;
        }
        return;
    }
    if (depth == n) return;
    dfs(depth+1);
    ofce[m++] = list[depth];
    dfs(depth+1);
    m--;
}

int main() {
    cin >> t;
    bool f = true;
    while (t--) {
        m = 0;
        ofce.clear();
        ofce.resize(5);
        mn_dis = 999999999;
        list.clear();
        if (!f) cout << endl;
        f = false;
        int x, y, val;
        set<int> office;
        cin >> n;
        if (n <= 5) {
            for (int i = 0; i < n; i ++) {
                cin >> x >> y >> val;
                office.emplace(5*x + y);
            }
            int ptr = 0;
            for (int i = 0; i < (5-n); i++) {
                while (office.count(ptr)) ptr++;
                office.emplace(ptr);
            }
            bool first = true;
            for (int v : office) {
                if (!first) cout << " ";
                first = false;
                cout << v;
            }
        } else {
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    city[r][c] = 0;
                }
            }
            for (int i = 0; i < n; i++) {
                cin >> x >> y >> val;
                list.push_back(5*x+y);
                city[x][y] = val;
            }
            dfs(0);
            sort(mx_ofce.begin(), mx_ofce.end());
            bool first = true;
            for (int &i : mx_ofce) {
                if (!first) cout <<" ";
                first = false;
                cout << i;
            }
            cout <<endl;
        }
    }
}
