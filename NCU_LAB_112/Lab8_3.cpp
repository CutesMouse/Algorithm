#include <iostream>
using namespace std;

int main() {
    int is, fs, st;
    cout << "Please input the size of the input array: \n";
    cin >> is;
    cout << "Please input the input array: \n";
    int arr1[is][is];
    for (int r = 0; r < is; r++) {
        for (int c = 0; c < is; c++) {
            cin >> arr1[r][c];
        }
    }
    cout << "Please input the size of the filter: \n";
    cin >> fs;
    int arr2[fs][fs];
    cout << "Please input the filter: \n";
    for (int r = 0; r < fs; r++) {
        for (int c = 0; c < fs; c++) {
            cin >> arr2[r][c];
        }
    }
    cout << "Please input the number of the stride: \n";
    cin >> st;
    cout << "Output array: \n";
    for (int r = 0; r < is; r += st) {
        for (int c = 0; c <is; c += st) {
            int ans = 0;
            for (int dr = 0; dr < fs; dr++) {
                for (int dc = 0; dc < fs; dc++) {
                    if (r + dr >= is || c + dc >= is) continue;
                    ans += arr1[r + dr][c + dc] * arr2[dr][dc];
                }
            }
            cout << ans << " ";
        }
        cout <<endl;
    }
}
