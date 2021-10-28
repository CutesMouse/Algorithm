#include <iostream> 
#include <cstring>
using namespace std;

int cur[30];
int r;

void dfs(int depth, int last, string s) {
	if (depth == r) {
		cout << s << endl;
		return;
	}
	for (int i = last; i < 30; i++) {
		if (cur[i]) {
			cur[i]--;
			string ns;
			ns.push_back((char) (i+'a'));
			dfs(depth+1,i,s + ns);
			cur[i]++;
		}
	}
}

int main() {
	string s;
	while (cin >> s) {
		cin >> r;
		memset(cur,0,sizeof(cur));
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			cur[(*iter) - 'a']++;
		}
		string b;
		dfs(0,0,b);
	}
}
