#include <iostream>
using namespace std;
int table[100][100];
int sample[100][100];
int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};

int main() {
    int H,W;
    cin >> H >> W;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cin >> table[x][y];
        }
    }
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            cin >> sample[x][y];
        }
    }
    long long int times = 0;
    for (int y = 0; y < H-1; y++) {
        for (int x = 0; x < W-1; x++) {
            int offset = sample[x][y] - table[x][y];
            times += abs(offset);
            for (int i = 0; i < 4; i++) {
                table[x+dx[i]][y+dy[i]] += offset;
            }
        }
    }
    bool not_ok = false;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x <W; x++) {
            not_ok = not_ok || sample[x][y] != table[x][y];
        }
    }
    if (not_ok) {
        cout << "No\n";
    } else cout << "Yes\n"<<times << "\n";
}
