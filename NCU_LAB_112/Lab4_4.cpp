#include <iostream>
using namespace std;

int pool[10] = {0};
int number = 0;
int sum = 0;

void dfs(int depth) {
    if (depth == 3) {
        cout << number << " ";
        sum += number;
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (!pool[i]) continue;
        number *= 10;
        number += i;
        pool[i] --;
        dfs(depth+1);
        pool[i] ++;
        number /= 10;
    }
}

int main() {
    int n, k;
    while (true) {
        cout << "How many numbers do you want to arrange: ";
        cin >> n;
        if (n >= 3 && n < 10) break;
        cout << "Wrong input!!! Please enter again!!!\n";
    }
    while (true) {
        bool valid = true;
        cout << "Please enter the unique integers: ";
        for (int i = 0; i < 10; i++) pool[i] = 0;
        for (int i = 0; i < n; i++) {
            cin >> k;
            if (k < 0 || k > 9) {
                valid = false;
                continue;
            }
            pool[k] ++;
        }
        for (int i = 0; i < 10; i++) valid = valid && (pool[i] < 2);
        if (valid) break;
        cout << "Wrong input!!! Please enter again!!!\n";
    }
    cout << "The three-digit numbers are:\n";
    dfs(0);
    cout << "\nThe sum: " << sum;
}
