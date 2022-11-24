#include <iostream>
using namespace std;
int main()
{
    int input;
    cout << "Please enter five-digit: ";
    cin >> input;
    int times = 1;
    //每次往後推進一個legit
    for (int i = 0; i < 5; i++)
    {
        times *= (input % 10);
        input /= 10;
    }
    printf("Answer=%d",times);
}

