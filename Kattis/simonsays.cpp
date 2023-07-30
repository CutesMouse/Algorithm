#include <iostream>
#include <cmath>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
    int N;
    string line;
    cin >> N;
    getline(cin, line);
    string target = "Simon says";
    regex reg(target+".+");
    while (N--) {
        getline(cin, line);
        if (regex_match(line, reg)) {
            cout << line.substr(target.size()) << endl;
        }
    }
}
