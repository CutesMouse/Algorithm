#include <iostream>

using namespace std;

void swap_shakerSort(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void shakerSort(int *arr, int n) {
    int changes = 0;
    int round = 1;
    do {
        changes = 0;
        int dx = (round % 2 ? 1 : -1);
        int st = (round % 2 ? 1 : (n-1));
        for (int i = st; i >= 1 && i < n; i += dx) {
            if (arr[i-1] <= arr[i]) continue;
            swap_shakerSort(arr[i-1], arr[i]);
            changes++;
        }
        if (changes) {
            cout << "Sorting round " << round++ << ": [";
            for (int i = 0; i < n; i++) {
                if (i) cout << " ";
                cout << arr[i];
            }
            cout << "]\n";
        }
    } while (changes);
}

int main (void) {
    int n;
    int arr[1000];
    cout << "Please input the array size: ";
    cin >> n;
    cout << "Please input the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    shakerSort(arr, n);

    cout << "After sorting: [";
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << "]\n";

    return 0;
}

