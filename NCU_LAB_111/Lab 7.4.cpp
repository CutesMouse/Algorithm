#include <iostream>
#include <cmath>
using namespace std;

unsigned long long int num;
int digit;

void print_triangle(int index, int line)
{
    if (index == (line+1))
    {
        cout << endl;
        line++;
        index = 0;
    }
    if (line == digit) return;

    int k = 0;
    if (index == 0) k = (num / (pow(10,digit-index-1)));
    else k = ((num / ((unsigned long long int) pow(10,digit-index-1))) % 10);

    cout << k << " ";
    print_triangle(index+1,line);
}
void print_inv_triangle(int index, int line)
{
    if (index < 0)
    {
        cout << endl;
        line++;
        index = line;
    }
    if (line == digit) return;

    int k = 0;
    if (index == 0) k = (num / ((unsigned long long int) pow(10,digit-index-1)));
    else k = ((num / ((unsigned long long int) pow(10,digit-index-1))) % 10);

    cout << k << " ";
    print_inv_triangle(index-1,line);
}

int main()
{
    cout << "Sequence: ";
    cin >> num;
    digit = floor(log10(num))+1;
    print_triangle(0,0);
    print_inv_triangle(0,0);

}
