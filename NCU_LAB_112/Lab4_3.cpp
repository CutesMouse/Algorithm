#include <iostream>
using namespace std;

int main() {
    int a = 1, b = 1;
    char oper = 'y';
    while (true) {
        do {
            if (a <= 0 || b <= 0) cout << "Wrong input!!! Please enter again!!!\n";
            cout << "Please enter two integers: ";
            cin >> a >> b;
        } while (a <= 0 || b <= 0);
        int hcf = 1;
        for (hcf = min(a,b); a % hcf != 0 || b % hcf != 0; hcf--);
        printf("The HCF of %d and %d is: %d\n", a, b, hcf);
        printf("The LCM of %d and %d is: %d\n", a, b, a * b / hcf);

        do {
            if (oper != 'y' && oper != 'n') cout << "Wrong input!!! Please enter again!!!\n";
            cout << "Do you want to find another LCM?[y/n] ";
            cin >> oper;
        } while (oper != 'y' && oper != 'n');
        if (oper == 'n') break;
    }
    cout << "BYE~";
}
