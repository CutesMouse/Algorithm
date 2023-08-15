#include <iostream>
#include <cmath>
using namespace std;

int main() {
	char table[100][100];
	string line;
	int n, sq;
	cin >> n;
	while (n--) {
		cin >> line;
		sq = sqrt(line.size());
		for (int r = 0; r < line.size(); r++) {
			table[r/sq][r%sq] = line[r];
		}
		for (int c = sq-1; c >= 0; c--) {
			for (int r = 0; r < sq; r++) {
				cout << table[r][c];
			}
		}
		cout << endl;
	}
}
