#include <iostream>
#include <deque>

using namespace std;

class teque {
private:
    deque<int> q1;
    deque<int> q2;

    void arrange() {
        int dif = q1.size() - q2.size();
        if (dif == 0 || dif == 1) return;
        while (dif > 1) {
            int temp = q1.back();
            q1.pop_back();
            q2.push_front(temp);
            dif = q1.size() - q2.size();
        }
        while (dif < 0) {
            int temp = q2.front();
            q2.pop_front();
            q1.push_back(temp);
            dif = q1.size() - q2.size();
        }
    }

public:
    void push_front(int n) {
        q1.push_front(n);
        arrange();

    }

    void push_back(int n) {
        q2.push_back(n);
        arrange();

    }

    void push_mid(int n) {
        q1.push_back(n);
        arrange();
    }

    int operator[](int n) {
        int base = (q1.size() + q2.size() + 1) / 2;
        if (n >= base) return q2[n - base];
        return q1[n];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string a;
    int val;
    teque t;
    while (n--) {
        cin >> a >> val;
        if (a == "push_front") t.push_front(val);
        if (a == "push_back") t.push_back(val);
        if (a == "push_middle") t.push_mid(val);
        if (a == "get") cout << t[val] << endl;
    }
}
