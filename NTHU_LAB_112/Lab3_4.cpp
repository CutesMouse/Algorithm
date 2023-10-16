#include <iostream>
#include <deque>
using namespace std;

int main() {
    string buffer;
    string source;
    bool f = true;
    while (getline(cin, source)) {
        deque<string> st;
        for (int i = 0; i < source.size(); i++) {
            char c = source[i];
            if (c == '[' || c == ']') {
                if (f) st.emplace_front(buffer);
                else st.emplace_back(buffer);
                f = (c == '[');
                buffer = "";
                continue;
            }
            buffer.push_back(c);
        }
        if (f) st.emplace_front(buffer);
        else st.emplace_back(buffer);
        buffer = "";
        for (auto &s : st) cout << s;
        cout << endl;
    }
}
