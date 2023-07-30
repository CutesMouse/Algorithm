#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    string s;
    cin >> N;
    getline(cin, s);
    while (N--) {
        bool used[256] = {0};
        getline(cin, s);
        for (char &c : s) {
            used[c] = true;
        }
        string missing;
        for (int i = 'a'; i <= 'z'; i++) {
            if (used[i] || used[i-'a'+'A']) continue;
            missing += (char) i;
        }
        if (!missing.empty()) cout << "missing " << missing << endl;
        else cout << "pangram"<<endl;
    }
}
