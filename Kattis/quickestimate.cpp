#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    string str;
    cin >> N;
    while (N--) {
        cin >> str;
        cout << str.length() << endl;
    }
}
