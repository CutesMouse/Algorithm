#include <iostream>
#include <map>
using namespace std;
int a[100000];
map<int,int> times;
int main() {
    int N, K;
    cin >> N >>K;
    for (int i = 0; i < N; i++) cin >> a[i];
    int from = 0, to =0;
    int longest = 0, kind = 0;;
    for (; from < N; from++) {
        for (; to < N; to++) {
            bool update = false;
            if (times[a[to]] == 0) {
                kind ++;
                times[a[to]] = 1;
                update = true;
            }
            if (kind > K) {
                times[a[to]] --;
                if (update) kind--;
                break;
            }
            longest = max(longest,to-from+1);
            //printf("from %d to %d distance: %d\n",from,to,longest);
            if (!update) times[a[to]] ++;
        }
        times[a[from]] --;
        if (!times[a[from]]) kind--;
    }
    cout << longest << endl;
}
