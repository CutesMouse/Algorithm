#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Please input a quinary number or -1 to exit: ";
    while (cin >> num && num != -1) {
        int cpy = num;
        int weight = 1;
        int ans = 0;
        bool valid = true;
        while (cpy > 0) {
            int digit = cpy % 10;
            cpy /= 10;
            if (digit >= 5) valid = false;
            ans += digit * weight;
            weight *= 5;
        }
        if (valid) printf("=== The decimal equivalent of the quinary number %d is %d. ===\n", num, ans);
        else printf("=== %d is not a valid quinary number!!! ===\n", num);
        cout << "Please input a quinary number or -1 to exit: ";
    }
    cout << "Bye~";
}
