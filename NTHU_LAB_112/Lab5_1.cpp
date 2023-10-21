#include <iostream>
#include <queue>
#define left leftq
#define right rightq
using namespace std;

typedef priority_queue<int, vector<int>> pql;
typedef priority_queue<int, vector<int>, greater<int>> pqr;

pql left;
pqr right;

void balance() {
    int s = left.size() + right.size();
    //cout << left.size() << " " << right.size() << endl;
    while (right.size() < (s/2)) {
        right.emplace(left.top());
        left.pop();
    }
    while (right.size() > (s/2)) {
        left.emplace(right.top());
        right.pop();
    }
}

int main() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (left.size() && k > left.top()) right.emplace(k);
        else left.emplace(k);
        balance();
        cout << left.top() << " ";
    }
}
