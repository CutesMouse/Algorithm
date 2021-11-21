#include <iostream>
#include <cstring>
#include <queue>
#define step first
#define pos second

using namespace std;
typedef pair<int, int> pp;
typedef priority_queue<pp, vector<pp>,greater<pp> > pppq;

int edge_table[9][9];
pp dis[1024];

void bond(int a, int b, int l) {
    edge_table[a][b] = l;
    edge_table[b][a] = l;
}

int main() {
    memset(edge_table,0,sizeof(edge_table));
    int n = 9;
    bond(0,1,4);
    bond(0,7,8);
    bond(1,7,11);
    bond(1,2,8);
    bond(7,8,7);
    bond(7,6,1);
    bond(8,6,6);
    bond(8,2,2);
    bond(2,3,7);
    bond(2,5,4);
    bond(6,5,2);
    bond(3,5,14);
    bond(3,4,9);
    bond(5,4,10);
    // 前面只是在建立測試用地圖
    for (int i = 0; i <n; i++) {
        dis[i] = {1000,0};
    }
    pppq pq;

    // x = step, y = pos
    // 這個順序是固定的，為了讓pq順利判斷
    pq.emplace(0,0);
    dis[0] = {0,0};

    while (!pq.empty()) {
        auto p = pq.top();
        //printf("%d, %d\n",p.first,p.second);
        pq.pop();
        for (int i =0; i < n;i++) {
            if (!edge_table[p.pos][i]) continue;
            if (dis[i].step > dis[p.pos].step + edge_table[p.pos][i]) {
                dis[i] = {dis[p.pos].step + edge_table[p.pos][i],p.pos};
                pq.emplace(p.step + edge_table[p.pos][i],i);
            }
        }
    }
    cout << dis[4].step << endl;
    int from = dis[4].pos;
    while (from) {
        cout << from << " < ";
        from = dis[from].pos;
    }
    cout << 0;

}
