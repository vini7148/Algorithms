#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

int major(vector<int> &a)
{
    int fl=0;
    sort(a.begin(),a.end());
    for(int i=0;i<(a.size()-1);i++)
    {
        int co=1;
        if(a[i]==a[i+1])
        {
            co=1;
            for(int j=i+1;j<a.size();j++)
            {
                if(a[i]!=a[j])
                {
                    i=j;
                    break;
                }
                else
                    co++;
            }
        }
        if(co>(a.size()/2))
        {
            fl=1;
        }
    }

    return fl;
}

int main()
{
    int n;
    cin>>n;
    //if(n<1)
        //n=1;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<major(a);
}
