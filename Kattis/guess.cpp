#include <iostream>
using namespace std;

int main() {
    int upper = 1000;
    int lower = 1;
    int mid;
    string res;
    while (res != "correct") {
        mid = lower + (upper - lower) / 2;
        cout << mid << endl;
        cin >> res;
        if (res == "lower") upper = mid - 1;
        else lower = mid + 1;
    }
    //cout << mid;
}
