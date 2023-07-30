#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int books[N];
    for (int i = 0; i < N; i++) cin >> books[i];
    sort(books, books+N);
    reverse(books, books+N);
    long long int price = 0;
    for (int i = 0; i < N/3; i++) {
        price += books[3*i] + books[3*i+1];
    }
    for (int i = 3 * (N/3); i < N; i++) {
        price += books[i];
    }
    cout << price;
}
