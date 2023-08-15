#include <iostream>
#include <regex>
#include <sstream>
#include <algorithm>

using namespace std;

bool cmp(pair<string,string> &a, pair<string,string> &b){
    if (a.first.length() == b.first.length()) return a.first < b.first;
    return a.first.length() < b.first.length();
}

int main() {
    regex num("\\d+");
    stringstream ss;
    int n;
    cin >> n;
    string size, color;
    pair<string, string> data[n];
    for (int i = 0; i < n; i++) {
        cin >> color >> size;
        if (regex_match(color, num)) {
            swap(size, color);
        } else {
            ss << size;
            int s;
            ss >> s;
            s *= 2;
            ss.clear();
            ss << s;
            ss >> size;
            ss.clear();
        }
        data[i] = {size, color};
    }
    sort(data, data+n, cmp);
    for (int i = 0; i < n; i++) cout << data[i].second << endl;
}
