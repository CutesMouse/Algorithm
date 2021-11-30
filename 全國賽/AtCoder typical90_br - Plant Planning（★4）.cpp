#include <iostream>
#include <algorithm>
using namespace std;
double mid(int *ary, int N) {
    if (N%2) {
        return ary[N/2];
    }
    return (ary[N/2-1] + ary[N/2])/2.0;
}
int main()
{
    int N;
    cin >>N;
    double sum = 0;
    int X[100000],Y[100000];
    for (int i = 0 ; i < N; i ++)
    {
        cin >> X[i] >> Y[i];
    }
    sort(X,X+N);
    sort(Y,Y+N);
    double mx = mid(X,N);
    double my = mid(Y,N);
    for (int i = 0; i < N; i++) {
        sum += abs(X[i] - mx);
        sum += abs(Y[i] - my);
    }
    cout << (long long int) sum << endl;
}
