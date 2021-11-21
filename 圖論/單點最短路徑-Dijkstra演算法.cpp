#include <iostream>
#include <cstring>
#include <queue>
#define step first
#define pos second

#define max_edge 30
// 此為最多的邊數

#define max_joint 9
// 此為最多的點數

using namespace std;

typedef pair<int, int> pp;
typedef priority_queue<pp, vector<pp>,greater<pp> > pppq;

vector<pp> eg_table[max_edge]; // 串接序列
int dis[max_joint]; // 到達每個頂點的暫時與確定最短路徑
int from[max_joint]; // 到達每個頂點前的停留點

void bond(int a, int b, int l) {
    // 將a與b串接，並設定權重(weight)
    eg_table[a].emplace_back(b,l);
    eg_table[b].emplace_back(a,l);
}

int main() {
    // 輸入測資
    int n = 9; // 總端點
    int S = 0; // 起始點
    int E = 4; // 終點
    // 由於此演算法的權重必為正數或0，距離合不會出現負數
    // 因此以 -1 表示無窮大
    memset(dis,-1,sizeof(dis));
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

    // 設定 priority queue(簡稱pq)
    // pair的首個項目(first)是 step、次個項目(second) 是 pos
    // 此順序不可對調 (pq特性: 優先比對first)
    pppq pq;
    // 將初始資料放入 pq
    pq.emplace(0,S);
    dis[S] = 0;
    // 開始dp
    while (!pq.empty()) {
        auto point = pq.top();
        pq.pop();
        // 這個路徑已經被後面的路徑覆蓋過了，不必再檢視
        if (point.step != dis[point.pos]) continue;
        // 終點的步數已經被確認，任務完成
        if (point.pos == E) break;
        // 往下延伸尋找端點
        for (auto iter = eg_table[point.pos].begin(); iter != eg_table[point.pos].end(); iter++) {
            // 目的地
            int i = iter->first;
            // 路徑權重
            int weight = iter->second;
            // 如果原本走過的路徑大小比較小，就不必檢查，直接跳過
            // 如果新路徑大小比原本更小，表示為較佳路徑，替換並加入pq
            if (dis[i] == -1 || dis[i] > point.step + weight) {
                // 新的路徑長
                dis[i] = point.step + weight;
                // 紀錄路徑，供之後回朔用
                from[i] = point.pos;
                // 新增回 pq，讓迴圈繼續延伸
                pq.emplace(dis[i],i);
            }
        }
    }
    // 最短路徑長即為 dis[E]
    printf("shortest path: %d\n",dis[E]);
    // 回朔路徑 (但順序會反過來，需要reverse)
    vector<int> path;
    int search = E;
    // 一步一步往上回推
    while (from[search] != S) {
        path.emplace_back(from[search]);
        search = from[search];
    }
    // 打印
    printf("%d",S);
    for (auto iter = path.rbegin(); iter != path.rend(); iter++) {
        printf(" -> %d",*iter);
    }
    printf(" -> %d",E);
}
