#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string line;
    while (n--) {
        cin >> line;
        if (line == "P=NP") {
            cout << "skipped\n";
            continue;
        }
        int a = 0;
        int b = 0;
        int* target = &a;
        for (int i = 0; i < line.size(); i++) {
            char c = line[i];
            if (c == '+') {
                target = &b;
                continue;
            }
            (*target) = (*target) * 10 + (c - '0');
        }
        cout << (a + b) << endl;
    }
}
