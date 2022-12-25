#include <iostream>
#include <cmath>
using namespace std;
void opt(unsigned long long int N, int x)
{
    if (!x) return;
    if (N == 0) {
        cout << "F(0) = 10\n";
        opt(10,x-1);
        return;
    }
    unsigned long long int K = 0;
    int last = -1;
    int cnt = 1;
    bool first = true;
    int total = floor(log10(N))+1;
    cout << "F("<<N<<") = ";
    for (int i = 0; i < total; i++)
    {
        int num = (N / ((long long int) pow(10,total-i-1))) % (10);
        if (last == num)
        {
            cnt++;
        }
        if (!first && last != num && cnt)
        {
            cout << cnt << last;
            K *= 100;
            K += cnt * 10 + last;
            cnt = 1;
        }
        first = false;
        last = num;
    }
    if (cnt)
    {
        cout << cnt << last;
        K *= 100;
        K += cnt * 10 + last;
        cnt = 0;
    }
    cout << endl;
    opt(K,x-1);
}
int main()
{
    unsigned long long int N;
    int x;
    cout << "Please enter a number N: \n";
    cin >>N;
    cout << "Please enter a number X: \n";
    cin >>x;
    cout << endl;
    opt(N,x);
}
