#include <iostream>
#include <vector>
using namespace std;

void swap(int *const a, int *const b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    vector<int> ids;
    int group = 0;
    bool fix = true;
    while (cin >> n)
    {
        if (cin.get() == '\n') fix = 0;
        group += fix;
        ids.push_back(n);
    }
    for (int i = 0 ; i < ids.size() / 2; i++)
    {
        swap(&ids[i], &ids[ids.size() - i - 1]);
    }
    if (ids.size() % 2)
    {
        swap(&ids[ids.size()/2], &ids[ids.size() - 1]);
    }
    group ++;
    for (int i = 0; i < ids.size(); i++)
    {
        if (i == group) cout << endl;
        cout << ids[i] << " ";
    }
}
