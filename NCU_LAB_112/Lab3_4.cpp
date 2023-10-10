#include <iostream>
using namespace std;

int main() {
    int mode, n, age;
    long long int price;
    cout << "Please choose the day for visiting the amusement park(0 for weekdays, 1 for holidays, and -1 to exit the program): ";
    while (cin >> mode && mode != -1) {
        cout << "How many people do you have: ";
        cin >> n;
        cout << "Please enter the age of each person: \n";
        price = 0;
        while (n--) {
            cin >> age;
            if (mode == 0) {
                if (age >= 0 && age <= 12) price += 50;
                if (age >= 13 && age <= 18) price += 100;
                if (age >= 19) price += 150;
            }
            if (mode == 1) {
                if (age >= 0 && age <= 12) price += 80;
                if (age >= 13 && age <= 18) price += 150;
                if (age >= 19) price += 200;
            }
        }
        printf("The total price is %lli.\n\n", price);
        cout << "Please choose the day for visiting the amusement park(0 for weekdays, 1 for holidays, and -1 to exit the program): ";
    }
}
