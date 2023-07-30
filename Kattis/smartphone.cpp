#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int point[10];
int main()
{
    int t,h,i,j;
    string word,typo,sug1,sug2,sug3;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>word;
        cin>>typo;
        cin>>sug1;
        cin>>sug2;
        cin>>sug3;
        point[1]=word.size();
        point[2]=word.size();
        point[3]=word.size();
        point[4]=word.size();
        for(j=0;j<typo.size();j++)
        {
            if(typo[j]==word[j]) point[1]-=1;
            else
            {
                point[1]+=typo.size()-j;
                break;
            }
        }
        for(j=0;j<sug1.size();j++)
        {
            if(sug1[j]==word[j]) point[2]-=1;
            else
            {
                point[2]+=sug1.size()-j;
                break;
            }
        }
        for(j=0;j<sug2.size();j++)
        {
            if(sug2[j]==word[j]) point[3]-=1;
            else
            {
                point[3]+=sug2.size()-j;
                break;
            }
        }
        for(j=0;j<sug3.size();j++)
        {
            if(sug3[j]==word[j]) point[4]-=1;
            else
            {
                point[4]+=sug3.size()-j;
                break;
            }
        }
        h=299999;
        point[2]+=1;
        point[3]+=1;
        point[4]+=1;
        for(j=1;j<=4;j++)
        {
            if(point[j]<h) h=point[j];
        }
        cout<<h<<"\n";
    }
    return 0;
}	
