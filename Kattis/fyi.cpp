#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    string phone;
    getline(cin, phone);
    cout << (phone[0] == '5' && phone[1] == '5' && phone[2] == '5');
}
