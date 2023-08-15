#include <iostream>

using namespace std;

int main() {
    int limit, n;
    string action;
    int people;
    int inside = 0;
    int forbid = 0;
    cin >> limit >> n;
    while (n--) {
        cin >> action >> people;
        if (action == "enter") {
            if (inside + people > limit) forbid++;
            else inside += people;
        } else {
            inside -= people;
        }
    }
    cout << forbid;
}
