#include <iostream>
#include <map>
using namespace std;

int dsu_1[200001];
int dsu_2[200001];

int find_root(int k, int* dsu) {
	if (dsu[k] == k) return k;
	return dsu[k] = find_root(dsu[k], dsu);
}

void group(int a, int b, int* dsu) {
	int ga = find_root(a, dsu);
	int gb = find_root(b, dsu);
	if (ga == gb) return;
	dsu[ga] = gb;
}

int main() {
	int n, k, l, a, b;
	cin >> n >> k >> l;
	for (int i = 0; i <= n; i++) dsu_1[i] = dsu_2[i] = i;
	while (k--) {
        cin >> a >> b;
		group(a, b, dsu_1);
	}
	while (l--) {
	    cin >> a >> b;
		group(a, b, dsu_2);
	}
	map<pair<int, int>, int> ans;

	for (int i = 0; i <= n; i++) {
        int i1 = find_root(i, dsu_1);
        int i2 = find_root(i, dsu_2);
		ans[{i1, i2}]++;
	}
	for (int i = 1; i <= n; i++) {
		int i1 = find_root(i, dsu_1);
        int i2 = find_root(i, dsu_2);
		cout << ans[{i1, i2}] << " ";
	}
}
