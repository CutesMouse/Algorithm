#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int l = b-a;
    if (l > 1) {
        printf("Dr. Chaz will have %d pieces of chicken left over!", l);
    } else if (l == 1) {
        printf("Dr. Chaz will have %d piece of chicken left over!", l);
    } else if (l == -1) {
        printf("Dr. Chaz needs %d more piece of chicken!", -l);
    } else {
        printf("Dr. Chaz needs %d more pieces of chicken!", -l);
    }
}
