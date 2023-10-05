#include <iostream>
using namespace std;

int main() {
    int date;
    int base = 0;
    int oper;
    cout << "Please enter the date: ";
    cin >> date;
    cout << "Please enter the mode you want to operate: \n1 for week\n2 for year\n";
    cin >> oper;
    int month = date / 100;
    int day = date % 100;
    if (month >= 2) base += 31;
    if (month >= 3) base += 28;
    if (month >= 4) base += 31;
    if (month >= 5) base += 30;
    if (month >= 6) base += 31;
    if (month >= 7) base += 30;
    if (month >= 8) base += 31;
    if (month >= 9) base += 31;
    if (month >= 10) base += 30;
    if (month >= 11) base += 31;
    if (month >= 12) base += 30;
    int week = (0 + base + day - 1) % 7;
    if (oper == 1) {
        printf("%04d is ", date);
        if (week == 0) cout << "Sunday";
        if (week == 1) cout << "Monday";
        if (week == 2) cout << "Tuesday";
        if (week == 3) cout << "Wednesday";
        if (week == 4) cout << "Thursday";
        if (week == 5) cout << "Friday";
        if (week == 6) cout << "Saturday";
        cout << ".";
    } else {
        printf("%04d is the %d day of this year.", date, base + day);
    }
}
