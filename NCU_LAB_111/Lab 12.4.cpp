#include <iostream>

using namespace std;

int **calculate(int **m1, int **m2, int r1, int c1, int r2, int c2)
{
    int **nm = new int*[r1];
    for (int r = 0; r < r1; r++)
    {
        *(nm+r) = new int[c2];
        for (int c = 0; c < c2; c++)
        {
            *((*(nm+r))+c) = 0;
            for (int k = 0; k < c1; k++)
            {
                *((*(nm+r))+c) += (*((*(m1 + r)) + k)) * (*((*(m2 + k)) + c));
            }
            cout << endl;
        }
    }
    return nm;
}

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix:\n";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix:\n";
    cin >> r2 >> c2;

    if (c1 != r2)
    {
        cout << "Cannot multiply these two matrixes.";
        return 0;
    }

    int **m1 = new int *[r1];

    for (int i = 0; i < r1; i++)
        *(m1 + i) = new int[c1];

    cout << "\nEnter matrix 1:\n";

    for (int i = 0; i < r1; i++)
    {
        for (int k = 0; k < c1; k++)
        {
            cin >> *((*(m1 + i)) + k);
        }
    }

    int **m2 = new int *[r2];

    for (int i = 0; i < r2; i++)
        *(m2 + i) = new int[c2];

    cout << "\nEnter matrix 2:\n";

    for (int i = 0; i < r2; i++)
    {
        for (int k = 0; k < c2; k++)
        {
            cin >> *((*(m2 + i)) + k);
        }
    }

    cout << "\nOutput Matrix:\n";

    int** nm = calculate(m1, m2, r1, c1, r2, c2);
    for (int r = 0; r < r1; r++)
    {
        for (int c = 0; c < c2; c++)
        {
            cout << *((*(nm+r))+c)<< " ";
        }
        cout << endl;
    }
}
