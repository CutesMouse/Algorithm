#include <iostream> 
using namespace std;
int main() {
	int l[6] = {1,1,2,2,2,8};
	for (int i = 0 ; i <6; i++) {
		int n;
		cin >> n;
		cout << (l[i] -n) << " ";
	}
}