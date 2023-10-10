#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Please enter a number: ";
    cin >> num;
    bool prime = true;
    for (int i = 2; i < num; i++) {
        prime = prime && (num % i);
    }
    if (num == 0 || num == 1) prime = false;
    if (prime) cout << num << " is prime!";
    else cout << num << " is not a prime number.";
}
