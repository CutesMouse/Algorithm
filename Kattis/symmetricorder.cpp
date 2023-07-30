#include <iostream>

using namespace std;

int main() {
    int set = 0;
    int N;
    string s[20];
    string ns[20];
    while (cin >> N && N) {
        cout << "SET " << (++set) << endl;
        for (int i = 0; i < N; i++) cin >> s[i];
        bool front = true;
        int left = 0, right = N-1;
        for (int i = 0; i < N; i++) {
            if (front) {
                ns[left++] = s[i];
            } else ns[right--] = s[i];
            front = !front;
        }
        for (int i = 0; i < N; i ++) cout << ns[i] << endl;
    }
}
