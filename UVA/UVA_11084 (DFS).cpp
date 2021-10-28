#include <iostream> 
#include <cstring>
using namespace std;

int cnt[10];
int d;
string s;
int ans = 0;
int maxn;

void dfs(int depth, long long int num) {
	if (depth == maxn) {
		if (num % d == 0) ans++;
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (cnt[i]) {
			cnt[i] --;
			dfs(depth+1,num*10 + i);
			cnt[i] ++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		cin >> s >> d;
		maxn = s.size();
		memset(cnt,0,sizeof(cnt));
		ans = 0;
		for (auto iter = s.begin(); iter != s.end(); iter++) {
			cnt[((*iter) - '0')]++;
		}
		dfs(0,0);
		cout << ans << endl;
	}
	
	
}
