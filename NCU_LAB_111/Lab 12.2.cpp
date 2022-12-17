#include <iostream>
using namespace std;

bool match(const char *a, const char *b)
{
    for (int i = 0; i < 4; i ++) if (*(a+i) != *(b+i)) return false;
    return true;
}

bool is_A(const char *ans, const char *guess, int pos)
{
    return (*(ans+pos) == *(guess+pos));
}

bool is_B(const char *ans, const char *guess, int pos)
{
    for (int i = 0; i < 4; i++)
    {
        if (i == pos) continue;
        if (*(ans+i) == *(guess+pos)) return true;
    }
    return false;
}

int main()
{
    char again = 0;
    char inputs[7] = {0};
    char guess_number[7] = {0};
    int guess = 0;
    do
    {
        guess = 0;
        //if (again) cout <<endl<<endl;
        cout << "*** Welcome to Bulls and Cows game ^o^ ***\n";
        cout << "Please enter the secret number: ";
        cin >> inputs;
        const char secret_number[5] = {*inputs,*(inputs+1),*(inputs+2),*(inputs+3),'\0'};
        do
        {
            cout << "Please make a guess: ";
            cin >> guess_number;
            guess++;
            if (match(guess_number, secret_number))
            {
                cout << "Congratulations!!! You hit the number!!!!\n";
                cout << "The total number of guess: " << guess <<endl;
                cout << "Do you want to play again (y/n)? ";
                cin >>again;
                break;
            }
            int A = 0, B = 0;
            for (int i = 0 ; i < 4; i++)
            {
                if (is_A(secret_number, guess_number, i)) {
                    A+= 1;
                    continue;
                }
                if (is_B(secret_number, guess_number, i)) {
                    B+=1;
                    continue;
                }
            }
            printf("You Missed. Your guess result ==> %dA%dB\n", A, B);
        }
        while (true);
    }
    while (again == 'y');
    cout << "Good-Bye!";
}
