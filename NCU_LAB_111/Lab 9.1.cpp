#include <iostream>
using namespace std;
int main()
{
    string input;
    cout << "Please enter a sentence: ";
    getline(cin,input);
    while (!input.empty())
    {
        cout << "'" << input[0] << "':";
        int number = 1;
        for (int i = 1; i < input.size(); i++)
        {
            if (input[i] == input[0]) {
                number++;
                input.erase(i,1);
                i--;
            }
        }
        input.erase(0,1);
        cout << number << endl;
    }

}
