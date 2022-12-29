#include <iostream>
using namespace std;

int calc() {
    string input;
    cin >> input;
    if (input == "f") {
        return 2 * calc() - 1;
    } else if (input == "g") {
        return calc() + 2 * calc() - 3;
    }
    return stoi(input);
}

int main() {
    cout << calc();
}
