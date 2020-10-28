#include <iostream>
#include <cstring>
using namespace std;
int tree[1000000];
short cnt[100005];
int pos[100005][2];
void build(int cur, int p, int q) {
    // 建構一棵二元樹
    if (p == q) {
        tree[cur] = 0;
        return;
    }
    int mid = (p+q) / 2;
    build(cur *2, p, mid);// Left
    build(cur * 2 + 1, mid+1, q); // Right
    tree[cur] = tree[cur*2] + tree[cur*2 + 1];
}
int query(int cur, int p, int q, int x, int y) {
    // p,q 是該tree所涵蓋範圍
    // x,y 是查詢範圍

    // 如果整段都涵蓋在樹的範圍裡面
    // 直接回傳樹的值
    if (x <= p && q <= y) {
        return tree[cur];
    }
    int res = 0;
    int mid = (p+q) /2;
    // 下層資訊:
    // 左段編號為: cur*2, 範圍 p ~ mid
    // 右段編號為: cur*2+1, 範圍 mid+1 ~ q

    //接下來要切割左右查詢

    // 如果x的值比中段還小 代表x有涵蓋到下層左半部
    if (x <= mid) {
        res += query(cur*2, p, mid, x, y);
    }
    // 如果y的值比中段+1還大 代表y有涵蓋到下層右半部
    if (y >= mid+1) {
        res += query(cur*2+1,mid+1,q,x,y);
    }
    return res;
}
void change(int cur, int p, int q, int pos, int val) {
    // 如果左右相碰 即找到了最底層 設定該層數值即可
    if (p == q) {
        tree[cur] = val;
        return;
    }
    // 否則就查看該位置是屬於下層的哪一邊
    // 再往下修改
    int mid = (p+q)/2;
    // 下層資訊:
    // 左: 編號cur*2, 範圍 p ~ mid
    // 右: 編號cur*2+1, 範圍 mid+1 ~ q

    // 如果修改的位置在下層左邊 就再往下更改左邊數據
    if (pos <= mid) {
        change(cur*2,p, mid,pos,val);
    } else {
        // 右邊則反之
        change(cur*2+1,mid+1,q,pos,val);
    }
    // 重新計算該層數據
    tree[cur] = tree[cur*2] + tree[cur*2+1];
}
int main() {
    int n,i,t;
    cin >> n;
    memset(cnt,0,sizeof(cnt));
    for (i = 0; i < n*2; i++) {
        cin >> t;
        pos[t][cnt[t]++] = i;
    }
    build(1,0,n+n-1);
    long long ans = 0;
    for (i = 1; i <= n; i++) {
        int x = pos[i][0];
        int y = pos[i][1];
        ans += query(1,0,n*2-1,x,y);
        change(1,0,n*2-1,x,1);
        change(1,0,n*2-1,y,1);
    }
    cout << ans << endl;
}
