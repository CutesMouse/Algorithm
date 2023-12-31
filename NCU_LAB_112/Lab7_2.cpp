#include <iostream>
using namespace std;

long long int grain(int depth, int N, long long int sum) {
    if (depth == N) return 0;
    return sum + grain(depth+1, N, sum * 2);
}

int main() {
    int N;
    while (true) {
        cout << "Please enter the number of squares N: ";
        cin >> N;
        if (N >= 1 && N <= 60) break;
        cout << "Illegal input!!! Please enter again!!!\n";
    }
    printf("There are %lli grains of wheat on the chessboard.", grain(0, N, 1));
}
