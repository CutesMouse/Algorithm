#include <iostream>
#include <vector>
#define int long long int
using namespace std;

vector<int> prime_factor[1000001];

void make_table() {
    prime_factor[1].emplace_back(1);
    for (int i = 2; i <= 1000000; i++) {
        if (prime_factor[i].size()) continue;
        for (int j = i; j <= 1000000; j+= i) {
            prime_factor[j].emplace_back(i);
        }
    }
}

int lowbit(int bit) {
    return bit & (-bit);
}

int cnt[1000001] = {0};

signed main() {
    make_table();
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 1) continue;
        for (int j = 1; j < (1<<prime_factor[x].size()); j++) {
            int mask = j;
            int multiply = 1;
            for (int S = 0; mask; mask ^=S) {
                S = lowbit(mask);
                multiply *= prime_factor[x][__lg(S)];
            }
            //cout << x <<": " <<multiply << "\n";
            cnt[multiply]++;
        }
    }
    int tot = n*(n-1)/2;
    for (int i = 2; i <= 1000000; i++) {
        //cout << "cnt " << i <<": " <<cnt[i] << endl;
        int flag = 1 - 2 * (prime_factor[i].size() % 2);
        tot += flag * (cnt[i] * (cnt[i]-1)) / 2;
    }
    cout << tot;
}
