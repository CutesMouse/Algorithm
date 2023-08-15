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
		sq = ceil(sqrt(line.size()));
		line.resize(sq*sq, 0);
		for (int r = 0; r < line.size(); r++) {
			table[r/sq][r%sq] = line[r];
		}
		for (int c = 0; c < sq; c++) {
			for (int r = sq-1; r >= 0; r--) {
				if (table[r][c]) cout << table[r][c];
			}
		}
		cout << endl;
	}
}
