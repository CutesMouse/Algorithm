#include <iostream>
#include <map>

using namespace std;

map<string, int> table;

void calc() {
    string temp;
    bool unknown = false;
    int multiplier = 1;
    int temp_num;
    int ans = 0;
    string input;
    while (cin >> temp && temp != "=") {
        input += (temp + " ");
        if (unknown) continue;
        if (temp == "+") {
            ans += (temp_num * multiplier);
            multiplier = 1;
        } else if (temp == "-") {
            ans += (temp_num * multiplier);
            multiplier = -1;
        } else {
            if (table.count(temp)) temp_num = table[temp];
            else unknown = true;
        }
    }
    ans += (temp_num * multiplier);
    string name;
    cout << input << "= ";
    if (!unknown) {
        for (auto &iter : table) {
            if (iter.second == ans) name = iter.first;
        }
    }
    if (unknown || name.empty()) cout << "unknown";
    else cout << name;
    cout << endl;
}

int main() {
    string cmd;
    string varname;
    int val;
    while (cin >> cmd) {
        if (cmd == "def") {
            cin >> varname >> val;
            table[varname] = val;
        }
        if (cmd == "calc") {
            calc();
        }
        if (cmd == "clear") {
            table.clear();
        }
    }
}
