#include <iostream> 
using namespace std;
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        char c= s.at(i);
        if (c >= 'A' && c <= 'Z') cout << c;
    }
}
