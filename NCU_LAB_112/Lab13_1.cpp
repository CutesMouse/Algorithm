#include <iostream>
using namespace std;

void print_led(int light) {
    for (int i = 0; i < 16; i++) {
        if (!((light>>(15-i))&1)) cout << "-";
        else cout <<"o";
    }
    cout << endl;
}

int main() {
    int num, times;
    cout << "number: ";
    cin >> num;
    cout << "times: ";
    cin >> times;
    int led = 0;
    for (int i = 0; i < 16; i++) {
        led = led << 1;
        led = led | ((bool) num);
        if (num) num--;
    }
    cout << "*** LED lights ***\n";
    // 1: right
    // 2: left
    int direction = 1;
    for (int i = 0; i <= times; i++) {
        print_led(led);
        if (led & 1) direction = 2;
        if ((led>>15)&1) direction = 1;
        if (direction == 1) led >>= 1;
        else led <<= 1;
    }
}
