#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
const int dx[4] = {0, 0, 1, 1};
const int dy[4] = {0, 1, 0, 1};

int main() {
    int r, c;
    int ans0 = 0, ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
    string line;
    cin >> r >> c;
    getline(cin, line);
    string park[r];
    for (int i = 0; i < r; i++) {
        getline(cin, park[i]);
    }
    for (int i = 0; i < r - 1; i++) {

        for (int j = 0; j < c - 1; j++) {
            int car = 0;
            int emp = 0;
            for (int k = 0; k < 4; k++) {
                emp += (park[i + dx[k]][j + dy[k]] == '.');
                car += (park[i + dx[k]][j + dy[k]] == 'X');
            }
            ans0 += (emp == 4);
            ans1 += (car == 1 && emp == 3);
            ans2 += (car == 2 && emp == 2);
            ans3 += (car == 3 && emp == 1);
            ans4 += (car == 4 && emp == 0);
        }
    }
    cout << ans0 << "\n";
    cout << ans1 << "\n";
    cout << ans2 << "\n";
    cout << ans3 << "\n";
    cout << ans4 << "\n";
    return 0;
}