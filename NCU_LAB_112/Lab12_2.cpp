#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string file;
    ifstream in;
    while (true) {
        cout << "Please enter the input file name: ";
        cin >> file;
        in.open(file);
        if (in) break;
        cout << "File could not be opened.\n";
    }
    char c;
    int sum = 0;
    while (in >> c) {
        if (c >= '0' && c <= '9') {
            sum += c - '0';
        }
    }
    printf("The sum is %d.", sum);
}
