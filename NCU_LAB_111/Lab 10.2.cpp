#include <iostream>
using namespace std;

int main(){
    int prime1 = 2, prime2 = 3, prime3 = 5;
    int num=0, result=0;

    int * ptr1 = &prime1;
    int * const ptr2 = &prime2;
    const int * ptr3 = &prime3;

    int *const result_ptr = &result;

    cin >> num;

    {
        int ptr4 = 0;
        *ptr1 = 0;
        *ptr2 = 0;
        while (!(num % 2)) {
            num /= 2;
            (*ptr1)++;
        }
        while (!(num % 3)) {
            num /= 3;
            (*ptr2)++;
        }
        while (!(num % 5)) {
            num /= 5;
            (ptr4)++;
        }
        const int ptr5 = ptr4;
        ptr3 = &ptr5;
        if ((*ptr1) || (*ptr2) || (*ptr3)) {
            *result_ptr = 1;
        }
    }

    cout << *ptr1 << " " << *ptr2 << " " << *ptr3 << endl;
    cout << *result_ptr << endl;

    return 0;
}

