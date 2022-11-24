#include <iostream>
using namespace std;
int main()
{
    int a,b;

    cout << "Please enter the first vector: \n";
    cin >> a >> b;
    pair<int,int> first = {a,b};

    cout << "Please enter the second vector: \n";
    cin >> a >> b;
    pair<int,int> second = {a,b};

    cout << "Please enter the mode you want to operate: \n";
    cout << "1 for plus\n";
    cout << "2 for subtract\n";
    cout << "3 for inner product\n";

    int mode;
    cin >> mode;
    switch (mode)
    {
    case 1:
        a = first.first + second.first;
        b = first.second + second.second;
        printf("The answer is (%d,%d).",a,b);
        break;
    case 2:
        a = first.first - second.first;
        b = first.second - second.second;
        printf("The answer is (%d,%d).",a,b);
        break;
    case 3:
        a = first.first * second.first + first.second * second.second;
        printf("The answer is %d.",a);
        break;
    }
}

