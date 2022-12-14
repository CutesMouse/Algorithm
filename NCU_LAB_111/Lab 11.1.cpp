#include <iostream>
using namespace std;

void EnterTheList(int *list, int arraysize){
    for (int i = 0; i < arraysize; i++) {
        cin >> *(list+i);
    }
};

void SelectionSort(int *const num, const int arraysize){
    for (int i = 0; i < (arraysize-1); i++) {
        for (int k = (i+1); k < arraysize; k++) {
            if (*(num+k) < *(num+i)) {
                swap(*(num+k),*(num+i));
            }
        }
    }
};

void Print(int *array, const int arraysize){
    cout << "After sorting:\n";
    for (int i = 0; i < arraysize; i++) cout << *(array+i) << " ";
};

int main(){
    int arraySize=0;
    cout << "Please enter the number of integer: ";
    cin >> arraySize;
    cout << "Please enter an integer list:" << endl;
    int list[arraySize];

    EnterTheList(list, arraySize);
    SelectionSort(list, arraySize);
    Print(list, arraySize);

    return 0;
}

