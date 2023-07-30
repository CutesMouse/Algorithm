#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ptr = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') {
            ptr--;
            continue;
        }
        s[ptr] = s[i];
        ptr++;
    }
    cout << s.substr(0, ptr);
}
