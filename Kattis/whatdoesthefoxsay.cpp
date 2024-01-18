#include <iostream>
#include <sstream>
#include <set>
using namespace std;

int main() {
    int t;
    string source, goes, snd;
    cin >> t;
    getline(cin, source);
    while (t--) {
        getline(cin, source);
        set<string> snds;
        while (getline(cin, goes) && goes != "what does the fox say?") {
            stringstream ss(goes);
            ss >> snd >> snd >> snd;
            snds.emplace(snd);
        }
        stringstream ss(source);
        while (ss >> snd) {
            if (snds.count(snd)) continue;
            cout << snd << " ";
        }
        cout << endl;
    }
}
