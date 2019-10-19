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
     return 1 + lcs(a, b, m-1, n-1);
   else
     return max(lcs(a, b, m, n-1), lcs(a, b, m-1, n));
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

    cout<<lcs(a,b,a.size(),b.size());
}
