#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    set<int> dis;
    for (int i = 0; i < 10; i++) {
        cin >> n;
        dis.insert(n % 42);
    }
    cout << dis.size();
}
