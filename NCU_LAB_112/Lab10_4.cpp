#include <iostream>
// YOU ARE ALLOWED TO USE OTHER LIBRARY

using namespace std;

void binary_transformation (const int size, const int transformation_base, int **ptr1, int **ptr2) {
    // THIS IS THE FUNCTION TO DO TRANSFORMATION
    // YOU CAN ONLY DO TRANSFORMATION IN THIS FUNCTION, NO OTHER FUNCTION CALLING IS ALLOWED
    // YOU CAN DECLARE PARAMETERS HERE BY YOURSELF
    // CODE BEGIN
    int &amount = **ptr2;
    int *arr = *ptr1;

    int dec = 0;
    for (int i = 0; i < size; i++) {
        dec *= 2;
        dec += *(arr+i);
    }

    int base = transformation_base;
    while (base <= dec) base *= transformation_base;
    amount = 0;
    while (base > 0) {
        amount *= 10;
        amount += dec / base;
        dec = dec % base;
        base /= transformation_base;
    }

    // CODE END
}

int main (void) {
    // YOU CAN ONLY DECLARE PARAMETERS WITH PARAMETERS BELOW
    // NO OTHER PARAMETERS ARE ALLOWED IN MAIN FUNCTION
    // CODE BEGIN TO DECLARE PARAMETERS
    int arr[30];
    int size;
    int amount;
    int transformation_base;
    int *ptr1;
    int *ptr2;
    // CODE END TO DECLARE PARAMETERS

    cout << "Please input the binary bit(s) size: ";
    cin >> size;
    cout << "Please input the binary bit(s) with space: ";

    // YOU CAN ONLY CODE MAIN FUNCTION HERE TO CIN THE INPUTS
    // CODE BEGIN TO CIN THE INPUTS
    for (int i = 0; i < size; i++) cin >> *(arr+i);
    ptr1 = arr;
    ptr2 = &amount;
    // CODE END TO CIN THE INPUTS

    cout << "Please input the transformation base: ";
    cin >> transformation_base;

    binary_transformation(size, transformation_base, &ptr1, &ptr2);

    cout << "After transformation, the result is " << amount << " in base " << transformation_base << ". " << endl;

    return 0;
}
