#include <iostream>
#include <string>

using namespace std;

int eva(string s)
{
    int a,b;
    char op;
    for(int i=0;i<s.length();i++)
    {
        if(isnum(s[i]]))
            a=s[i];
        else
            op=s[i];
    }
}

int main()
{
    string s;
    cin>>s;
    cout<<eva(s);
}
