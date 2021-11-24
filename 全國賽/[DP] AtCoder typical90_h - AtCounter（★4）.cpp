#include <iostream>
#include <cstring>
using namespace std;
string target = "atcoder";
string source;
long long int d[100000][10];
long long int dp(int end, int search) {
	if (search == -1) return 1;
	if (end < 0) return 0;
	if (d[end][search] != -1) return d[end][search];
	long long int ans = 0;
	if (source[end] == target[search]) {
		ans += dp(end-1,search-1);
	}
	ans += dp(end-1,search);
	ans %= (1000000007);
	d[end][search] = ans;
	return ans;
}
int main() {
	int N;
	cin >> N;
	cin >> source;
	memset(d,-1,sizeof(d));
	cout << dp(N-1,target.size()-1) % (1000000007);
}
