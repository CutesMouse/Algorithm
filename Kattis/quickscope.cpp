#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

vector<set<string>> scp;
int N;

map<string, vector<string>> dict;

bool has_declared(string idt) {
    return dict.count(idt) != 0 && dict[idt].size() != 0;
}

bool can_declare(string idt) {
    return scp.back().count(idt) == 0;
}

string tof(string idt) {
    if (!has_declared(idt)) return "UNDECLARED";
    return dict[idt].back();
}

void declare(string type, string idt) {
    scp.back().emplace(idt);
    dict[idt].emplace_back(type);
}

void add_branch() {
    scp.emplace_back();
}

void pop_branch() {
    for (auto idt : scp.back()) {
        dict[idt].pop_back();
    }
    scp.pop_back();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    //freopen("testcase.txt", "w", stdout);
    cin >> N;
    scp.emplace_back();
    string a, b;
    while (N--) {
        cin >> a;
        if (a == "TYPEOF") {
            cin >> b;
            cout << tof(b) << endl;
        } else if (a == "{") {
            add_branch();
        } else if (a == "}") {
            pop_branch();
        } else {
            cin >> a >> b;
            if (can_declare(a)) declare(b, a);
            else {
                cout << "MULTIPLE DECLARATION";
                return 0;
            }
        }
    }
}
