#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, G;
    int guests[1000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> G;
        for (int j = 0; j < G; j++) {
            cin >> guests[j];
        }
        sort(guests, guests+G);
        int diff;
        for (int j = 0; j < G; j++) {
            if (j == 0) {
                if (guests[j] != guests[j+1]) diff = guests[j];
            }
            else if (j == G-1) {
                if (guests[j] != guests[j-1]) diff = guests[j];
            } else {
                if (guests[j] != guests[j+1] && guests[j] != guests[j-1]) diff = guests[j];
            }
        }
        cout << "Case #" << (i+1) << ": " << diff << endl;
    }
}
