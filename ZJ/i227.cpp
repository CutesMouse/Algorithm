#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int ignore = 0;
    cin >> ignore;
    stack<int> st;
    int mode = 0;
    int arg;
    while (cin >> mode)
    {
        switch(mode)
        {
        case 1:
            cin >> arg;
            st.push(arg);
            break;
        case 2:
            if (!st.size()) cout << -1 << "\n";
            else cout << st.top() << "\n";
            break;
        case 3:
            if (st.size()) st.pop();
            break;
        }
    }

}
