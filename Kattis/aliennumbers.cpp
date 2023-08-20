#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Case #" << i << ": ";
        string an, source, target;
        cin >> an >> source >> target;
        int number = 0;
        for (int i = 0; i < an.size(); i++) {
            number *= source.size();
            number += find(source.begin(), source.end(), an[i]) - source.begin();
        }
        string ans;
        while (number > 0) {
            ans += target[number%target.size()];
            number /= target.size();
        }
        cout << string(ans.rbegin(), ans.rend()) << endl;
    }
}
