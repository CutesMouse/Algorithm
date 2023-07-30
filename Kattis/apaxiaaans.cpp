#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string word;
    string modified;
    cin >> word;
    modified += word[0];
    for (int i = 1; i < word.size(); i++) {
        if (word[i] == word[i-1]) continue;
        modified += word[i];
    }
    cout << modified;
}
