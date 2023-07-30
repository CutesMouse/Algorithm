#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
string str[1000];
bool alpha[26]={0};
int main()
{
    string key,answer,ans="",out="",newkey="";
    char table[5][5],c;
    alpha['q'-'a']=true;
    int i,j,b,t,k,l,m=99,n=98,o=97,p=96,ptr;
    int delta='a'-'A';
    getline(cin,key);
    getline(cin,answer);
    for(i=0;i<key.size();i++)
    {
        if(key[i]>='a'&&key[i]<='z')
        {
            key[i]-=delta;
            newkey+=key[i];
        }
    }
    for(i=0;i<answer.size();i++)
    {
        if(answer[i]>='a'&&answer[i]<='z')
        {
            ans+=answer[i];
        }
    }

    for(i=0;i<ans.size();i++)
    {
        ans[i]-=delta;
    }

    b=0;
    t=0;
    for(i=0;i<ans.size();i++)
    {


        if(b==0)
        {
            str[t]+=ans[i];
            b=1;
        }
        else if(b==1&&str[t][0]==ans[i])
        {
            str[t]+='X';
            b=0;
            i-=1;
            t+=1;
        }
        else if(b==1)
        {
            str[t]+=ans[i];
            b=0;
            t+=1;
        }
    }
    if (!str[t].empty()) {
        str[t] += "X";
        t++;
    }

    ptr=0;
    for(i=0;i<newkey.size();i++)
    {
        char c=newkey[i];
        if(alpha[c-'A']) continue;
        alpha[c-'A']=true;
        table[ptr/5][ptr%5]=c;
        ptr++;
    }
    for(i=0;i<26;i++)
    {
        char c='A'+i;
        if(alpha[c-'A']) continue;
        alpha[c-'A']=true;
        table[ptr/5][ptr%5]=c;
        ptr++;
    }

    for(i=0;i<t;i++)
    {

        for(j=0;j<5;j++)
        {
            for(k=0;k<5;k++)
            {
                if(str[i][0]==table[j][k])
                {
                    m=j;
                    n=k;
                }
                if(str[i][1]==table[j][k])
                {
                    o=j;
                    p=k;
                }

            }
        }
        if(m==o)
        {
            out+=table[m][(n+6)%5];
            out+=table[o][(p+6)%5];
        }
        if(n==p)
        {
            out+=table[(m+6)%5][n];
            out+=table[(o+6)%5][p];
        }
        if(m!=o&&n!=p)
        {
            out+=table[m][p];
            out+=table[o][n];
        }

    }
    cout<<out<<"\n";
    return 0;
}
