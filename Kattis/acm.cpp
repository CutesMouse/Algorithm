#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int points = 0;
    int solved = 0;
    int attempt[26] = {0};
    int t;
    char c;
    string s;
    while (cin >> t && t != -1) {
        cin >> c >> s;
        if (s == "right") {
            solved++;
            points += t;
            points += (attempt[c-'A'] * 20);
            continue;
        }
        attempt[c-'A']++;
    }
    cout << solved << " " << points;
}
