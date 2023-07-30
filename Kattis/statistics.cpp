#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n,tmp,amc;
	vector<int> nums;
	int casec = 1;
	while (cin >> n) {
		amc = n;
		nums.clear();
		while (n--) {
			cin >> tmp;
			nums.push_back(tmp);
		}
		sort(nums.begin(),nums.end());
		int min = nums[0];
		int max = nums[amc-1];
		cout << "Case " << casec << ": " <<min << " " << max <<" "<< max-min << endl;
		casec++;
	}
}