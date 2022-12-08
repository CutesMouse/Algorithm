#include <iostream>
using namespace std;

void insertionSort(int * const, const int);


int main()
{
    int array[5];
    for(int i=0; i<5; i++){
        cin >> array[i];
    }
    cout << "Insertion sort" << endl;
    insertionSort(array, 5);

    return 0;
}

void insertionSort(int * const array, const int size){
    for (int pos = 1; pos < size; pos++) {
        int insert = pos;
        int val = array[pos];
        while (insert > 0 && array[insert-1] > val) {
            array[insert] = array[insert-1];
            insert--;
        }
        array[insert] = val;
        for (int i = 0; i < size; i++) cout << array[i] << " ";
        cout <<endl;
    }
};
