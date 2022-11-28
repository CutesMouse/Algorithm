#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quick_sort(vector<int> &v, int from, int to)
{
    if (to - from <= 0) return;
    int i = from,j = to;
    while (i != j)
    {
        while (i != j && v[from] >= v[j]) j--;
        while (i != j && v[to] <= v[i]) i++;
        if (i != j) swap(v[i],v[j]);
    }
    swap(v[from], v[j]);
    quick_sort(v, from, i-1);
    quick_sort(v, i + 1, to);
}

int main()
{
    vector<int> v;
    int last = -999999, n;
    while (cin >> n)
    {
        if (last != -999999)
        {
            v.push_back(last);
        }
        last = n;
    }
    if (last > v.size() || last <= 0)
    {
        cout << "Out of range";
        return 0;
    }
    //quick_sort(v,0, v.size()-1);
    sort(v.rbegin(), v.rend());
    cout << "After sorting:\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << "\nThe " << last;
    if (last == 11 || last == 12 || last == 13) cout << "th";
    else
    {
        switch (last % 10)
        {
        case 1:
            cout << "st";
            break;
        case 2:
            cout << "nd";
            break;
        case 3:
            cout << "rd";
            break;
        default:
            cout << "th";
        }
    }
    cout << " largest number is " << v[last-1];
}
