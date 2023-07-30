#include <iostream>

using namespace std;

struct node {
    string val;
    node *next;
    node *last;
};

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    int a, b;
    node nodes[n];
    for (int i = 0; i < n; i++) {
        cin >> s;
        nodes[i] = {s, nullptr, nullptr};
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        if (nodes[a].last != nullptr) {
            nodes[a].last->next = nodes + b;
            nodes[a].last->last = nodes + b;
            nodes[a].last = (nodes[b].last == nullptr ? (nodes + b) : (nodes[b].last));
            continue;
        }
        nodes[a].next = &nodes[b];
        nodes[a].last = (nodes[b].last == nullptr ? (nodes + b) : (nodes[b].last));
    }
    node *nd = &nodes[a];
    while (nd != nullptr) {
        cout << nd->val;
        nd = nd->next;
    }
}
