#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main() {
    map<string, string> dictionary;
    stringstream ss;
    string line, en, fr;
    while (getline(cin, line) && !line.empty()) {
        ss << line;
        ss >> en >> fr;
        dictionary[fr] = en;
        ss.clear();
    }

    while (getline(cin, line)) {
        if (dictionary.count(line)) cout << dictionary[line] << endl;
        else cout << "eh\n";
    }
}
