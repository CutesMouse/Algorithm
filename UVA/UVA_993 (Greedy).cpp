#include <iostream>
using namespace std;
// i 從9下來數
// 如果cn是i的倍數
// 就把cn丟到px裡面
// 最後輸出px
int main() {
	int l;
	cin >> l;
	while (l--) {
		int cn;
		cin >> cn;
		if (cn == 1) {
			cout << "1" << endl;
			continue;
		}
		string px = "";
		for (int i = 9; i > 1; i--) {
			if (cn == 1) break;
			while (cn % i == 0) {
				px += to_string(i);
				cn /= i;
			}
		}
		if (cn != 1) {
			cout << "-1\n";
			continue;
		}
		for (int i = px.size()-1; i >=0; i--) cout << px.at(i);
		cout << endl;
	}
}
