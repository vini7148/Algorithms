#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pi(long long int n);

int mi(vector<int> ans,int n)
{
    vector<int> a;
    a=pi(n);
    return a.size()+ans.size()-2;
}

vector<int> pi(long long int n)
{
    vector<int> ans;
    while(n>=1)
    {
        ans.push_back(n);
        if (n % 3 == 0)
        {
            int a3=mi(ans,n/3);
            int a1=mi(ans,n-1);
            if(a3<a1)
                n /= 3;
            else if(n%2!=0)
                n = n - 1;
            else
                n /= 2;
        }
        else if (n % 2 == 0)
        {
            int a2=mi(ans,n/2);
            int a1=mi(ans,n-1);
            if(a2<a1)
                n /= 2;
            else if(n%3!=0)
                n = n - 1;
            else
                n /= 3;
        }
        else
        {
            n = n - 1;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    long long int n;
    cin>>n;
    vector<int> a;
    a=pi(n);
    cout<<a.size()-1<<"\n";
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
}
