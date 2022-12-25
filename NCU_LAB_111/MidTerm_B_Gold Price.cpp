#include <iostream>
#include <cmath>
using namespace std;
unsigned long long int trend;
int length;

int get_digit(int n) {
    unsigned long long int trend = ::trend;
    return (trend / ((unsigned long long int) pow(10,length - n - 1)))%10;
}
int main() {
    int profit = 0;
    cout << "Please enter the trend of gold price: \n";
    cin >> trend;
    length = floor(log10(trend))+1;

    for (int i = 0; i < length-1; i++) {
        if (get_digit(i+1) > get_digit(i)) profit += get_digit(i+1) - get_digit(i);
    }
    cout << "The maximum profit is "<<profit<<".";

}
