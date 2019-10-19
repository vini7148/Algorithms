#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs(vector<int> a,vector<int> b, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if (a[m-1] == b[n-1])
    {
        return 1 + lcs(a, b, m-1, n-1);
    }
   else
     return max(lcs(a, b, m, n-1), lcs(a, b, m-1, n));
}

vector<int> ls(vector<int> a,vector<int> b, int m, int n )
{
   vector<int> cc;
   if (m == 0 || n == 0)
     return cc;
   if (a[m-1] == b[n-1])
    {
        cc.push_back(a[m-1]);
        lcs(a, b, m-1, n-1);
    }
   else
     max(lcs(a, b, m, n-1), lcs(a, b, m-1, n));

    return cc;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    int m;
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++)
        cin>>b[i];

    vector<int> cc;
    cc=ls(a,b,a.size(),b.size());

    int o;
    cin>>n;
    vector<int> c(o);
    for(int i=0;i<o;i++)
        cin>>c[i];

    cout<<lcs(cc,c,cc.size(),c.size());
}
