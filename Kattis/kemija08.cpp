#include <iostream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    for (int i = 0; i < line.size(); i++) {
        char c = line[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') i += 2;
        cout << c;
    }
}
