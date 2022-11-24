#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int ary[3];
    cout << "Input three lengths for a triangle: ";
    for(int i = 0; i < 3; i++) cin >> ary[i];
    sort(ary,ary+3);
    if ((ary[0] + ary[1]) > ary[2])
    {
        cout << "These data can be a triangle.";
    }
    else cout << "These data cannot be a triangle.";
}

