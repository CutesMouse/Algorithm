#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


int main()
{
    string sentence;
    int i,p=0,delta;
    delta='a'-'A';
    while(getline(cin,sentence))
    {
        for(i=0;i<sentence.size();i++)
        {
            if(sentence[i]>='A'&&sentence[i]<='Z')
            {
                sentence[i]=sentence[i]+delta;
            }
        }
        p=0;
        for(i=0;i<sentence.size()-6;i++)
        {
            if ((i+6) >= sentence.size()) break;
            if(sentence[i]=='p'&&sentence[i+1]=='r'&&sentence[i+2]=='o'&&sentence[i+3]=='b'&&sentence[i+4]=='l'&&sentence[i+5]=='e'&&sentence[i+6]=='m')
            {
                p=1;
                cout<<"yes\n";
                break;
            }


        }
        if(p==0)
        {
            cout<<"no\n";
        }

    }

    return 0;
}