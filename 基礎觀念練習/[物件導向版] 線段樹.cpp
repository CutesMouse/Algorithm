#include <iostream>
#include <cstring>
using namespace std;

class SegmentTree
{
public:

    SegmentTree(int n)
    {
        this->n = n;
        //由數學證明推導得知，最少要開四倍大小
        tree = new int[4*n];
        memset(tree, 0, sizeof(int) * 4 * n);
    }

    SegmentTree(int n, int* vals) //n為長度、vals為原始陣列
    {
        this->n = n;
        tree = new int[4*n];
        //建樹
        build_tree(0, n-1, 1, vals);
    }
    //區間查詢，左右都是閉區間
    int query_sum(int from, int to)
    {
        return query_sum(from, to, 0, n-1, 1);
    }
    //插入(新增)某數進某位置
    void insert_num(int pos, int val)
    {
        insert_num(0, n-1, pos, val, 1);
    }
    //區間修改
    void range_append(int from, int to, int val)
    {
        range_append(from, to, 0, n-1, val, 1);
    }
private:
    int n; //線段長度
    int *tree; //線段樹的資料
    //建立線段樹
    //參數: 左區間範圍, 右區間範圍, id, 陣列資料
    int build_tree(int left, int right, int id, int* vals)
    {
        //左邊界等於右邊界，即為最小線段
        if (left == right)
        {
            //直接填寫線段的值
            tree[id] = vals[left];
            return vals[left];
        }
        //左右邊界的值也要更改
        int sum = 0;
        int mid = (right+left)/2;
        sum += build_tree(left, mid, id<<1|0, vals);
        sum += build_tree(mid+1, right, id<<1|1, vals);
        return tree[id] = sum;
    }
    //區間查詢
    //參數: 查詢左邊界, 查詢右邊界, 左區間範圍, 右區間範圍, id
    int query_sum(int from, int to, int left, int right, int id)
    {
        // ----from----left---right---to---
        //左右邊界不斷縮減，直到整條線段都包含在查詢範圍的時候，回傳當前的值
        if (from <= left && right <= to) return tree[id];
        //邊界還沒有完全包在查詢界內，要分左右討論
        int sum = 0;
        int mid = (right+left)/2;
        //--left--from----right(mid)--- (對於下一層的左區塊而言)
        //橫跨到下一層的左線段，要加入這邊的值
        if (from <= mid) sum += query_sum(from, to, left, mid, id<<1|0);
        //--left(mid+1)----to---right--- (對於下一層的右區塊而言)
        //橫跨到下一層的右線段，要加入這邊的值
        if (mid < to) sum += query_sum(from, to, mid+1,right, id<<1|1);
        return sum;
    }
    //單點編輯(append)
    //參數: 左區間範圍, 右區間範圍, 編輯位置, 值, id
    void insert_num(int left, int right, int pos, int val, int id)
    {
        //縮減到最小限度，直接更改當前的值
        if (left == right)
        {
            tree[id] += val;
            return;
        }
        //自己本身也有包含這個值
        //因此自己也要更改
        tree[id] += val;
        int mid = (left+right)/2;
        //--left----pos----right(mid) (對於下一層而言)
        //更改的位置位在左邊界內
        if (pos <= mid) insert_num(left, mid, pos, val, id<<1|0);
        //位在右邊界內
        else insert_num(mid+1, right, pos, val, id<<1|1);
    }
    //區間修改
    //參數: 左修改範圍, 右修改範圍, 左區間範圍, 右區間範圍, 值, id
    void range_append(int from, int to, int left, int right, int val, int id)
    {
        //縮減到剩一項
        if (left == right)
        {
            tree[id] += val;
            return;
        }
        int mid = (left + right) / 2;
        //---from---left---right---to
        //整段包含在區間範圍，因此整段的值都要跟著改動
        if (from <= left && right <= to)
        {
            //(a+k) + (b+k) + (c+k) +... = (a+b+c+...) + n*k
            tree[id] += val * (right - left + 1);
            //左右都要加
            range_append(from, to, left, mid, val, id<<1|0);
            range_append(from, to, mid+1, right, val, id<<1|1);
            return;
        }
        //有包到的部分是 右邊right和to較小的一個 和 左邊from和left較大的一個
        tree[id] += (min(right, to) - max(from, left) + 1) * val;
        //包到左界
        if (from <= mid) range_append(from, to, left, mid, val, id<<1|0);
        //包到右界
        if (to > mid) range_append(from, to, mid+1, right, val, id<<1|1);
    }
};

int main()
{
    SegmentTree tree(100);
    tree.range_append(0, 98, 10);
    tree.insert_num(99, 1);
    cout << tree.query_sum(97, 99);
}
