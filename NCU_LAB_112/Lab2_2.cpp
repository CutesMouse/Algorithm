#include <iostream>
using namespace std;

int main() {
    int num;
    int oper;
    cout << "Please enter five-digit: ";
    cin >> num;
    cout << "Please enter the arithmetic you want to operate:\n1 for addition\n2 for multiplication\n";
    cin >> oper;
    cout << "Answer=";
    int ans = (oper-1);
    while (num > 0) {
        if (oper == 1) ans += num%10;
        else ans *= num % 10;
        num /= 10;
    }
    cout << ans;
}
