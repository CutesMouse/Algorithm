#include <iostream>
using namespace std;

long long int get_area(long long int w, long long int l) {
    return w * l;
}

int main()
{
    cout << "Please enter the width and length: ";
    int w,l;
    cin >> w >> l;
    long long int a = get_area(w,l);
    if (a <= 2147483647) {
        cout << "Area: "<<a<<", only need 4 bytes to store the value. (int)";
    } else {
        cout << "Area: "<<a<<", need 8 bytes to store the value. (long long)";
    }
}
