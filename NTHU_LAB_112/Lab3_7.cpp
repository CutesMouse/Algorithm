#include <iostream>
#include <map>
#define maxn 1000005
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int val;
    int head;
    int tail;
};

Node *head[maxn];
Node* tail[maxn];
Node* index[maxn];
int n;

void prt() {
    for (int i = 1; i <= n; i++) {
        cout << "#" << i << ":";
        if (head[i]) {
            Node* ptr = head[i];
            while (ptr != nullptr) {
                cout << " " << ptr->val;
                ptr = ptr->next;
            }
        }
        cout << "\n";
    }
}

void move_back(int a, int b) {
    Node* na = index[a];
    Node* nb = index[b];
    if (na->head) {
        head[na->head] = na->next;
        if (na->next) na->next->head = na->head;
        na->head = 0;
    }
    if (na->tail) {
        tail[na->tail] = na->prev;
        if (na->prev) na->prev->tail = na->tail;
        na->tail = 0;
    }
    if (nb->tail) {
        tail[nb->tail] = na;
        na->tail = nb->tail;
        nb->tail = 0;
    }
    if (na->prev) {
        na->prev->next = na->next;
    }
    if (na->next) {
        na->next->prev = na->prev;
    }
    if (nb->next) {
        nb->next->prev = na;
    }
    na->prev = nb;
    na->next = nb->next;
    nb->next = na;
}

void move_all(int ha, int hb) {
    if (head[ha] == nullptr) return;
    if (tail[hb] == nullptr) {
        head[hb] = head[ha];
        tail[hb] = tail[ha];
        head[hb]->head = hb;
        tail[hb]->tail = hb;
        head[ha] = nullptr;
        tail[ha] = nullptr;
        return;
    }
    tail[hb]->next = head[ha];
    head[ha]->prev = tail[hb];
    head[ha]->head = 0;

    tail[hb]->tail = 0;
    tail[hb] = tail[ha];
    head[hb]->tail = 0;
    tail[ha]->tail = hb;
    head[ha] = nullptr;
    tail[ha] = nullptr;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        Node* n = new Node();
        n->val = i;
        n->head = i;
        n->tail = i;
        head[i] =n;
        tail[i] = n;
        index[i] = n;
    }
    int x, a, b;
    for (int i = 0; i < q; i++) {
        cin >> x >> a >> b;
        if (!x) {
            move_back(a, b);
        } else move_all(a, b);
    }
    prt();
}
