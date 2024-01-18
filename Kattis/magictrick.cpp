#include <iostream>
#include <set>
using namespace std;

int main() {
    string in;
    set<char> cs;
    getline(cin, in);
    for (auto c : in) {
        if (cs.count(c)) {
            cout << 0;
            return 0;
        }
        cs.emplace(c);
    }
    cout << 1;
}
