#include <iostream>
#include <cstring>
#define SIZE 100000
using namespace std;
int tree[SIZE*8];
bool used[SIZE+1];
int map[SIZE+1][2];

int query(int id, int l, int r, int tl, int tr) {
//    printf("executed query %d,%d,%d,%d,%d\n",id,l,r,tl,tr);
    //-l-tl-------tr-r-
    if (l <= tl && r >= tr) return tree[id];
    int mid = (tr + tl) >> 1;
    int total = 0;
    if (l <= mid) {
        //--r---m------
        total += query((id << 1),l,r,tl,mid);
    }
    if (r > mid) {
        //-----m---r---
        total += query((id << 1)+1,l,r,mid+1,tr);
    }
    return total;
}

void modify(int id, int tl, int tr, int pos, int val) {
//    printf("executed modify %d,%d,%d,%d,%d\n",id,tl,tr,pos,val);
    if (tr == tl) {
        tree[id] = val;
        return;
    }
    int mid = (tr+tl) >> 1;
    if (pos <= mid) {
        //--p---m------
        modify((id << 1), tl,mid,pos,val);
    } else {
        modify((id << 1)+1, mid+1, tr,pos,val);
    }
    tree[id] = tree[id << 1] + tree[(id << 1) +1];
}

int main() {
    int n;
    cin >> n;
    memset(used,0,sizeof(used));
    memset(map,0,sizeof(map));
    memset(tree,0,sizeof(tree));
    int k;
    for (int i = 0; i < 2*n; i++) {
        cin >> k;
        map[k][used[k]] = i;
//        printf("map [%d][%d] = %d\n",k,used[k],i);
        used[k] = true;
    }
    long long int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += query(1,map[i][0],map[i][1],0,n*2);
        modify(1,0,n*2,map[i][0],1);
        modify(1,0,n*2,map[i][1],1);
    }
    cout << sum;
}
