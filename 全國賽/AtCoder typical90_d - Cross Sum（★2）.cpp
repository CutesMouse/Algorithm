#include <iostream>
using namespace std;
int table[2005][2005];
int w[2005],l[2005];
int main() {
	int n,m;
	cin >> m >> n;
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			cin >> table[x][y];
			w[x] += table[x][y];
			l[y] += table[x][y];
		}
	}
	
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			cout << w[x] + l[y] - table[x][y] << " ";
		}
		cout << endl;
	}
	
} 
