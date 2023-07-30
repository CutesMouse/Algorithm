#include <iostream>
#include <algorithm>

using namespace std;

int main() {
   int N, t;
   int a;
   int done = 0;
   cin >> N >> t;
   while (N--) {
       cin >> a;
       if (t >= a) {
           done++;
           t -= a;
       } else break;
   }
   cout << done;
}
