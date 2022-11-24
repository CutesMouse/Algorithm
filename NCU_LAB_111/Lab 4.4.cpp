#include <iostream>
using namespace std;
int main()
{
    char seq[250];
    char first_term;
    int nt, los;
    cout << "Please enter the first term of sequence: ";
    cin >> first_term;
    cout << "Please enter the number of terms: ";
    cin >> nt;
    cout << "Please enter the length of the square: ";
    cin >> los;

    char ptr = first_term;
    for (int i = 0; i < 250; i++)
    {
        if (!(i % (nt))) ptr = first_term;
        seq[i] = ptr;
        ptr++;
        if (ptr > 'Z') ptr = 'A';
    }

    for (int i = 0; i < los; i++)
    {
        if (i == 0)
        {
            for (int k = 0; k < los ; k++)
            {
                cout << seq[k] << " ";
            }
        }
        else if (i == (los-1))
        {
            int f = 3*(los-1);
            for (int k = f; k > (f-los); k--)
            {
                cout << seq[k] << " ";
            }
        }
        else
        {
            int f = (4*(los-1) - 1) - (i) + 1;
            int l = los + i - 1;
            cout << seq[f] << " ";
            for (int k = 0; k < los-2; k++) cout << "  ";
            cout << seq[l] << " ";
        }
        cout << endl;
    }

}

