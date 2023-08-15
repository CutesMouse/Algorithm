#include <iostream>
using namespace std;

int main() {
    int dx[4] = {0, 1, 0, 1};
    int dy[4] = {0, 0, 1, 1};

    string s;
    cin >> s;
    cout << s.size() << " ";
    int x = 0;
    int y = 0;
    for (int i = 0; i < s.size(); i++) {
        x *= 2;
        y *= 2;
        x += dx[s[i] - '0'];
        y += dy[s[i] - '0'];
    }
    cout << x << " " << y;
}
