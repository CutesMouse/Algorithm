#include <iostream>
using namespace std;

int calc() {
    string input;
    cin >> input;
    if (input == "f") {
        return 2 * calc() - 3;
    } else if (input == "g") {
        return 2 * calc() + calc() - 7;
    } else if (input == "h") {
        return 3 * calc() - 2 * calc() + calc();
    }
    return stoi(input);
}

int main() {
    cout << calc();
}
