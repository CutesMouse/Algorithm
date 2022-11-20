#include <iostream>
using namespace std;

void insertion_sort(int* ary, const int size) {
    //概念: 每次往下推進一位
    //若pos = k 可以確定 0~k-1前都已經sort完成
    //接著把ary[k]插入到0~k-1之間
    for (int pos = 1; pos < size; pos++) {
        int insert = pos;
        int val = ary[pos];
        while (insert > 0 && ary[insert-1] > val) {
            ary[insert] = ary[insert-1];
            insert--;
        }
        ary[insert] = val;
    }
}

int main() {
    int k[5] = {5,4,3,2,1};
    insertion_sort(k,5);
    for (int &p : k) cout << p << " "; //1 2 3 4 5
}
