#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack<char> stk;
    string s;
    getline(cin, s);
    for (char &c : s) {
        if (stk.size() && stk.top() == 'S' && c == 'T') stk.pop();
        else stk.emplace(c);
    }
    cout << stk.size();
}
