#include <iostream>
using namespace std;
int main()
{
    bool ignore = true;
    int n;
    string str;
    cin >> n;
    while (n--) {
        cin >> str;
        ignore = !ignore;
        if (ignore) continue;
        cout << str << endl;
    }
}
