#include <iostream>

using namespace std;

int main() {
    int N;
    int p;
    int pressed_time = 0;
    bool pressed = false;
    int tot = 0;
    cin >> N;
    while (N--) {
        cin >> p;
        if (pressed) {
            tot += (p - pressed_time);
        } else pressed_time = p;
        pressed = !pressed;
    }
    if (pressed) cout << "still running";
    else cout << tot;
}
