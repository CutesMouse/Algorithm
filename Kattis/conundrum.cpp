#include <iostream>
using namespace std;
int main()
{
    string target = "PER";
    int day = 0;
    string item;
    cin >> item;
    for (int i = 0; i < item.size(); i++) {
        char c = item[i];
        day += (target[i%3] != c);
    }
    cout << day;
}
