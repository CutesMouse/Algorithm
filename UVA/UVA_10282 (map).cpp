#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string,string> map;
    string line;
    while (getline(cin,line)) {
        if (line.empty()) break;
        string first = line.substr(0,line.find(' '));
        string second = line.substr(first.size()+1);
        map[second] = first;
    }
    while (cin >> line) {
        auto pos = map.find(line);
        if (pos == map.end()) {
            cout << "eh" << endl;
            continue;
        }
        cout << pos->second << endl;
    }
}
