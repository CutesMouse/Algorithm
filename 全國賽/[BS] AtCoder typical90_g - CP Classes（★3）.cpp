#include <algorithm>
#include <iostream>
using namespace std;
int A[300000];
int N;
int bs(int from, int to, int target) {
	int index = -1;
	while (from < to) {
		int mid = (from+to) /2;
		if (A[mid] > target) {
			//---target---mid
			index = mid;
			to = mid;
		} else from = mid+1;
	}
	return from;
}
int main() {
	cin >> N;
	for (int i = 0; i <N; i++) {
		cin >> A[i];
	}
	sort(A,A+N);
	int Q;
	cin >> Q;
	for (int i = 0; i < Q ; i++) {
		int temp;
		cin >> temp;
		int index = bs(0,N,temp);
		int first = index-1;
		int last = index;
		if (first < 0) first = last;
		first = A[first];
		last = A[last];
		cout << min(abs(first-temp),abs(last-temp)) << endl;
	}
	
}
