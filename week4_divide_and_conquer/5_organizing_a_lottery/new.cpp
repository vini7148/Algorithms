#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int mi;

long long no(vector<long long> s,vector<long long> e,long long n)
{
    /*long long co=0;
    for(long long i=0;i<(n+1)/2;i++)
    {
        if(s[i]<=pt && pt<=e[i])
        {
            co++;
        }
        if(s[n-i-1]<=pt && pt<=e[n-1-i])
        {
            co++;
        }
        if((n-i-1)==i && co>0)
            co--;
    }
    return co;*/

    int ma=max(e);
    mi=min(s);
    for(int i=mi;i<=ma;i++)
    {

    }

}

int main()
{
    long long n,m;
    cin>>n>>m;

    vector<long long> s(n),e(n);
    for(long long i=0;i<n;i++)
        cin>>s[i]>>e[i];

    vector<long long> pt(m);
    for(long long i=0;i<m;i++)
        cin>>pt[i];

    vector<int> ans;
    ans=no(s,e,n);

    for(long long i=0;i<m;i++)
        cout<<ans[pt[i]-mi]<<" ";
}
