#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cout << "Please enter the total pages: ";
        cin >> n;
        if (n == -1) break;
        int page = 0;
        int sum = 0;
        do {
            page++;
            sum += page;
        } while (sum <= n);
        printf("The original total number of pages in the book is %d, and the missing page is %d.\n", sum, sum - n);
    } while(true);
}
