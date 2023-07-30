#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int count;
	cin >> count;
	while (count--) {
		int n;
		cin >> n;
		vector<string> v;
		while (n--) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(),v.end());
		vector<string>::iterator iter = unique(v.begin(),v.end());
		cout << distance(v.begin(),iter);
		cout << endl;
	}
} 