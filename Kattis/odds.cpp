#include <iostream>
#include <numeric>
using namespace std;

char input[4];
int pool = 0;
// all with respect to X
// 0: lose
// 1: tie
// 2: win
int mia() {
	int x0 = input[0] - '0';
	int x1 = input[1] - '0';
	int r0 = input[2] - '0';
	int r1 = input[3] - '0';
    int x = max(x0, x1) * 10 + min(x0, x1);
    int r = max(r0, r1) * 10 + min(r0, r1);
    int win = -1;
    if (x == r) {
        return 1;
    }
    if (x == 21) win = 0;
    else if (r == 21) win = 1;
    else if (x0 == x1 && r0 != r1) win = 0;
    else if (x0 != x1 && r0 == r1) win = 1;
    else win = r > x;

    return win ? 0 : 2;
}

int win_condition(int w = 0) {
	if (w == 4) {
		pool++;
		return mia() == 2;
	}
	if (input[w] != '*') {
		return win_condition(w+1);
	}
	int k = 0;
	for (int i = 0; i < 6; i++) {
		input[w] = '0' + i + 1;
		k += win_condition(w+1);
		input[w] = '*';
	}
	return k;
}

int main() {
	while (cin >> input[0] >> input[1] >> input[2] >> input[3] && input[0] != '0') {
		pool = 0;
		int w = win_condition();
		if (w == 0 || w == pool) {
			cout << w/pool << endl;
			continue;
		}
		int g = gcd(w, pool);
		cout << w/g << "/" << pool/g << endl;
	}
}
