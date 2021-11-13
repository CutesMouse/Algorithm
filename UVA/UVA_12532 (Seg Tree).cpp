#include <iostream>
#include <cstring>
#define SIZE 100000

using namespace std;

short tree[4*SIZE];

void modify(int id, int pos, short val, int tl, int tr) {
    if (tl == tr) {
        tree[id] = val;
        return;
    }
    int mid = (tl+tr) >> 1;
    // l--p-m----r
    if (pos <= mid) {
        modify(id <<1,pos,val,tl,mid);
    } else {
        modify((id << 1)+1,pos,val,mid+1,tr);
    }
    tree[id] = tree[id << 1] * tree[(id << 1) +1];
}

short query(int id, int l, int r, int tl, int tr) {
    // ---l--tl---tr---r---
    if (l <= tl && r >= tr) return tree[id];
    int mid = (tl+tr) >> 1;
    // tl-l---m------tr
    short total = 1;
    if (l <= mid) {
        total *= query(id << 1, l, r, tl, mid);
    }
    // tl-----m--r---tr
    if (r > mid) {
        total *= query((id << 1) +1, l, r, mid+1, tr);
    }
    return total;
}

short flat(int n) {
    if (n > 0) return 1;
    if (n < 0) return -1;
    return 0;
}

int main() {
    int N,K,X,X1,X2;
    char M;
    while (cin >> N >> K) {
        memset(tree,0,sizeof(tree));
        for (int i = 0; i < N; i++) {
            cin >> X;
            modify(1,i,flat(X),0,N-1);
        }
        for (int i = 0; i < K; i++) {
            cin >> M >> X1 >> X2;
            X1--;
            if (M == 'C') {
                modify(1,X1,flat(X2),0,N-1);
            } else {
                short multiply = query(1,X1,X2-1,0,N-1);
                if (multiply > 0) cout << "+";
                else if (multiply == 0) cout << "0";
                else cout << "-";
            }
        }
        cout << endl;
    }
}
