#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <vector>
using namespace std;

int mn = (1<<30);
int dis(int a, int b) {
	return abs(a/5-b/5) + abs(a%5-b%5);
}

void prt_set(set<int> &s) {
	bool first = true;
	for (int i : s) {
		if (!first) cout << " ";
		first = false;
		cout << i;
	}
}

void dfs(vector<int> &sel, int m, int depth, map<int, int> &city, set<int> &ans) {
	if (m == 5) {
		int tot = 0;
		for (auto iter = city.begin(); iter != city.end(); iter++) {
			int j = (1<<30);
			for (int &i : sel) {
				int k = dis(i, iter->first) * iter->second;
				if (k < j) {
					j = k;
				}
			}
			tot += j;
		}
	//	printf("mn: %d, tot: %d\n", mn, tot);
		if (tot < mn) {
			ans.clear();
			for (int &i : sel) ans.emplace(i);
			mn = tot;
		}
		return;
	}
	if (depth >= city.size()) return;
	auto iter = city.begin();
	for (int i = 0; i < depth; i++) iter++;
	sel[m++] = iter->first;
	dfs(sel, m, depth+1, city, ans);
	m--;
	dfs(sel, m, depth+1, city, ans);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		mn = (1<<30);
		cin >> n;
		int x, y, val;
		set<int> ans;
		map<int, int> city;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> val;
			int id = x * 5 + y;
			city[id] = val;
		}
		if (city.size() < 5) {
			int ptr = 0;
			for (int i = 0; i < (5-n); i++) {
				while (city.count(ptr)) ptr++;
				ans.emplace(ptr++);
			}
			for (auto iter = city.begin(); iter != city.end(); iter++) ans.emplace(iter->first);
		} else {
			vector<int> selected(5);
			int m = 0;
			dfs(selected, m, 0, city, ans);
		}
		prt_set(ans);
		cout << endl;
	}
}
