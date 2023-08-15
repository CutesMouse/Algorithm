#include <iostream>

using namespace std;

int main() {
    bool partition[102] = {false};
    int w, p, n;
    cin >> w >> p;
    for (int i = 0; i < p; i++) {
        cin >> n;
        partition[n] = true;
    }
    partition[0] = true;
    partition[w] = true;
    for (int diff = 1; diff <= w; diff++) {
        for (int start = 0; (start + diff <= w); start++) {
            if (partition[start] && partition[start+diff]) {
                cout << diff << " ";
                break;
            }
        }
    }
}
