#include <iostream>

using namespace std;

int nums[5];
int comps[5], prime[5];
int comp_index = 0, prime_index = 0;

bool is_prime(int k) {
    for (int i = 2; i < k; i++) {
        if (!(k % i)) return false;
    }
    return true;
}

int main() {
    cout << "Please input unique data for 5 positive integers: ";
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
        if (nums[i] == 1 || nums[i] == 0) continue;
        if (is_prime(nums[i])) prime[prime_index++] = nums[i];
        else comps[comp_index++] = nums[i];
    }
    if (comp_index) {
        cout << "Composite number: ";
        bool first = true;
        for (int i = 0; i < comp_index; i++) {
            int k = comps[i];
            if (!first) cout << ",";
            first = false;
            cout << k;
        }
    }
    if (prime_index) {
        if (comp_index) cout << endl;
        cout << "Prime number: ";
        bool first = true;
        for (int i = 0; i < prime_index; i++) {
            int k = prime[i];
            if (!first) cout << ",";
            first = false;
            cout << k;
        }
    }
}
