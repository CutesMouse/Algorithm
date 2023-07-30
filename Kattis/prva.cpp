#include <iostream>

using namespace std;

int main() {
    int r, c;
    string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzz";
    cin >> r >> c;
    string data[r];
    for (int i = 0; i < r; i++) {
        cin >> data[i];
    }
    for (int i = 0; i < r; i++) {
        string temp = "";
        for (int j = 0; j < c; j++) {
            if (data[i][j] == '#') {
                if (temp.size() > 1) ans = min(temp, ans);
                temp = "";
                continue;
            }
            temp += data[i][j];
        }
        if (temp.size() > 1) ans = min(temp, ans);
    }
    for (int j = 0; j < c; j++) {
        string temp = "";
        for (int i = 0; i < r; i++) {
            if (data[i][j] == '#') {
                if (temp.size() > 1) ans = min(temp, ans);
                temp = "";
                continue;
            }
            temp += data[i][j];
        }
        if (temp.size() > 1) ans = min(temp, ans);
    }
    cout << ans;
}
