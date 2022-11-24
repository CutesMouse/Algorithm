#include <iostream>
using namespace std;
int main() {
    cout << "Input the vector: ";
    int a,b;
    cin >> a >> b;

    printf("Clockwise perpendicular vector is (%d,%d).\n",b,-a);
    printf("Counterclockwise perpendicular vector is (%d,%d).",-b,a);
}

