#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    int tree[100000];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> tree[i];
    sort(tree, tree+N);
    reverse(tree, tree+N);
    int day = N;
    for (int i = 0; i < N; i++) {
        day = max(day, tree[i] + (i+1));
    }
    cout << day+1;
}
