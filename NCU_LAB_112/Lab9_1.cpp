#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void insertion_sort(vector<int> &ary, const int size) {
    for (int pos = 1; pos < size; pos++) {
        int insert = pos;
        int val = ary[pos];
        while (insert > 0 && ary[insert-1] < val) {
            ary[insert] = ary[insert-1];
            insert--;
        }
        ary[insert] = val;
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line == "z") break;
        stringstream ss;
        ss << line;
        int n;
        vector<int> v;
        while (ss >> n) v.push_back(n);
        insertion_sort(v, v.size());
        for (int &i : v) cout << i << " ";
        cout <<endl;
    }
}
