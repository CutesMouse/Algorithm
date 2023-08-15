#include <iostream>
using namespace std;

int main() {
	string name[3] = {"Adrian", "Bruno", "Goran"};
	string seq[3] = {"ABC", "BABC", "CCAABB"};
	int pts[3] = {0};
	int n;
	char c;
	cin >> n;
	for (int j = 0; j < n; j++) {
		cin >> c;
		for (int i = 0; i < 3; i++) {
			pts[i] += (seq[i][j%seq[i].size()] == c);
		}
	}
	int mx = -1;
	for (int i = 0; i < 3; i++) {
		if (pts[i] > mx) {
			mx = pts[i];
		}
	}
	cout << mx << endl;
	for (int i = 0; i < 3; i++) {
		if (pts[i] == mx) cout << name[i] << endl;
	}
}
