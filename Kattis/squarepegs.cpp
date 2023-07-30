#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n,m,k,input;
	int amount = 0;
	cin >> n >> m >> k;
	vector<int> circle;
	vector<double> plot;
	while (n--) {
		cin >> input;
		circle.push_back(input*2);
	}
	while (m--) {
		cin >> input;
		plot.push_back(input*2);
	}
	while (k--) {
		cin >> input;
		plot.push_back(input*sqrt(2));
	}
	sort(circle.begin(),circle.end());
	sort(plot.begin(),plot.end());
	int lastFind = 0;
	for (int i = 0; i < plot.size(); i++) {
		int p = plot[i];
		for (int tier = lastFind; tier < circle.size(); tier++) {
			int ps = circle[tier];
			if (ps > p) {
				lastFind = tier+1;
				//cout << "Match! "<<p << " " << ps << "\n";
				amount++;
				break;
			}
		}
	}
	cout << amount;
} 