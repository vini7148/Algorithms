#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

int ma(vector<long long int>a,int n)
{
    int co=0,ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<(n+1)/2;i++)
    {
        co=0;
        if(a[i]==a[i+1])
        {
            for(int j=i;j<n-1;j++)
            {
                if(a[i]!=a[i+1])
                   break;
                else
                    co++;
            }
        }
        if(co>n/2)
        {
            ans=1;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<long long int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<ma(a,n);
}
