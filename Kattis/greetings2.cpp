#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string hey;
    cin >> hey;
    cout << "h" << hey.substr(1, hey.size()-2) << hey.substr(1, hey.size()-2) << "y";
}
