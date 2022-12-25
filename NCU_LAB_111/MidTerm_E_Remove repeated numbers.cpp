#include <iostream>
#include <cmath>
using namespace std;


void simplify(unsigned long long int &k)
{
    if (!k) return;
    unsigned long long int modified = 0;
    unsigned long long int weight = 1;

    unsigned long long int removed = 0;
    unsigned long long int removed_weight = 1;

    int last = -1;
    do
    {
        int num = k %10;
        k /= 10;
        if (num == last)
        {
            removed += (num * removed_weight);
            removed_weight *= 10;
            continue;
        }
        last = num;
        modified += (num * weight);
        weight *= 10;
    }
    while (k > 0);
    if (!removed)
    {
        k = modified * 64;
        return;
    }
    k = modified * pow(2,floor(log2(removed))+1) + removed;
    k *= 64;
    k += floor(log2(removed))+1;
}

int main()
{
    unsigned long long int k;
    cin >> k;
    simplify(k);

    cout << (k/64) / ((long long int) pow(2,k % 64)) << endl;
    cout << (k/64) % ((long long int) pow(2,k % 64));

    return 0;
}
