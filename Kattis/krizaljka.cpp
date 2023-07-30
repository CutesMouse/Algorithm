#include <iostream>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int bond_x = -1, bond_y = -1;
	for (int x = 0; x < a.size(); x++) {
		for (int y = 0; y < b.size(); y++) {
			if (a.at(x) == b.at(y)) {
				bond_x = x;
				bond_y = y;
				break;
			}
		}
		if (bond_x != -1 && bond_y != -1) break;
	}
	for (int y = 0; y < b.size(); y++) {
		for (int x = 0; x < a.size(); x++) {
			if (y == bond_y) {
				cout << a.at(x);
				continue;
			}
			if (x == bond_x) {
				cout << b.at(y);
				continue;
			}
			cout << ".";
		}
		cout << endl;
	}
} 