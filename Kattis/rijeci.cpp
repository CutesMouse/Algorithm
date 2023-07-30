#include <iostream>
#include <cstring>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << "0 1";
		return 0;
	}
	int table[46];
	memset(table,0,sizeof(table));
	table[1] = 1;
	table[2] = 2;
	for (int i =3; i < n; i++) {
		table[i] = table[i-1] + table[i-2];
	}
	cout << table[n-2] << " " << table[n-1];
}