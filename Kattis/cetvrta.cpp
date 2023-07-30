#include <iostream>
using namespace std;
int dist(int a, int b, int c) {
	if (a == b) return c;
	if (b == c) return a;
	if (a == c) return b;
}
int main() {
	int i[3][2];
	for (int a = 0; a <3; a++) {
		for (int b = 0; b <2; b++) {
			cin >> i[a][b];
		}
	}
	cout << dist(i[0][0], i[1][0],i[2][0]) << " " << dist(i[0][1], i[1][1], i[2][1]);
} 