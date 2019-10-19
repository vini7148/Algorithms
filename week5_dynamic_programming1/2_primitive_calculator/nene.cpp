#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> func( int n );

int mi(vector<long long int> ans,int n)
{
    vector<long long int> a;
    a = func(n);
    return a.size()+ans.size()-2;
}

vector<long long int> func( int n )
{
    vector<long long int> ans;
    ans.push_back( n );
    while(n>0)
    {
        /*if(mi(ans,n-1)==(mi(ans,n)-1))
            n--;
        else if(n%2==0 && mi(ans,n/2)==(mi(ans,n)-1))
            n/=2;
        else if(n%3==0 && mi(ans,n/3)==(mi(ans,n)-1))
            n/=3;*/
        if (n % 3 == 0)
        {
            int a3=mi(ans,n/3);
            int a1=mi(ans,n);
            if(a3<=a1-1)
                n /= 3;ans.push_back( n );
            /*else if(n%2!=0)
                n = n - 1;
            else
                n /= 2;*/
        }
        if (n % 2 == 0)
        {
            int a2=mi(ans,n/2);
            int a1=mi(ans,n);
            if(a2<=a1-1)
                n /= 2;ans.push_back( n );
            /*else if(n%3!=0)
                n = n - 1;
            else
                n /= 3;*/
        }
        if (mi(ans,n-1)<mi(ans,n))
        {
            n = n - 1;ans.push_back( n );
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> a;
    a = func( n );
    cout << a.size() - 1 << "\n" ;
    for(int i=0;i<a.size();i++)
        cout << a[i] << " " ;
}
