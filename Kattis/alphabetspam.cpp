#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    string line;
    int space = 0, lower = 0, upper = 0, symbol = 0;
    cin >> line;
    for (int i = 0; i < line.size(); i++) {
        char c = line[i];
        if (c == '_') space++;
        else if (c >= 'a' && c <= 'z') lower++;
        else if (c >= 'A' && c <= 'Z') upper++;
        else symbol++;
    }
    cout << fixed << setprecision(15);
    cout << space / (double) line.size() << endl;
    cout << lower / (double) line.size() << endl;
    cout << upper / (double) line.size() << endl;
    cout << symbol / (double) line.size() << endl;
}
