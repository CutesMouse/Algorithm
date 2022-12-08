#include <iostream>
#define FOR(var,sing) for (int var = 0; var <= ((**ptr) / sing); var++)
using namespace std;

void find_currency(int **ptr){
    int a,b,c,d;
    int k = 0;
    cin >> a >> b >> c >> d;
    cin >> (**ptr);
    FOR(ma,a) {
        FOR(mb,b) {
            FOR(mc,c) {
                FOR(md,d) {
                    int amount = a*ma+b*mb+c*mc+d*md;
                    if (amount == (**ptr)) k++;
                }
            }
        }
    }
    **ptr = k;
}

int main() {
    int amount=0;

    int *ptr_ways = &amount;
    find_currency(&ptr_ways);
    cout << amount;

    return 0;
}
