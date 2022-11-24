#include <iostream>
using namespace std;
int main()
{
    bool ed = false;
    do
    {
        int r1, r2;
        int divisor;
        cout << "Please enter the range: \n";
        do
        {
            cin >> r1;
            if (r1 == -1) {
                ed = true;
                break;
            }
            if (r1 <= 0) {
                cout << "Out of Range!!! Please enter again!!!\n";
            } else break;
        } while (true);
        if (ed) {
            cout << "Bye~";
            return 0;
        }
        do
        {
            cin >> r2;
            if (r2 <= 0) {
                cout << "Out of Range!!! Please enter again!!!\n";
            } else break;
        } while (true);
        cout << "Please enter a divisor: \n";
        do
        {
            cin >> divisor;
            if (divisor <= 0) {
                cout << "Out of Range!!! Please enter again!!!\n";
            } else break;
        } while (true);
        int cnt = 0;
        if (r1 > r2) {
            swap(r1,r2);
        }
        for (int i = r1; i <= r2; i++) {
            if (!(i % divisor)) cnt++;
        }
        if (cnt == 1) {
            printf("==== There is a divisible number between [%d~%d] ====\n",r1,r2);
        } else if (cnt == 0) {
            printf("==== There isn't any divisible number between [%d~%d] ====\n",r1,r2);
        } else {
            printf("==== There are %d divisible numbers between [%d~%d] ====\n",cnt,r1,r2);
        }
    } while (true);
}

