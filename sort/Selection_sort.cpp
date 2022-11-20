#include <iostream>
using namespace std;

void selection_sort(int *ary, int size) {
    //概念: 每次找到剩餘序列中最小的元素放到第一個
    for (int i = 0; i < (size-1); i++) {
        for (int k = i+1; k < size; k++) {
            if (ary[k] < ary[i]) swap(ary[i], ary[k]);
        }
    }
}

int main() {
    int k[5] = {10,12,100,56,30};
    selection_sort(k, 5);
    for (int &p : k) cout << p << " ";
}
