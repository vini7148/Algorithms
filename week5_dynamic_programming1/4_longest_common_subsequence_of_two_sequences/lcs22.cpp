#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs(vector<int> a,vector<int> b, int m, int n )
{
   int co=0;
   while(1)
   {
       if(m<0 || n<0)
            break;
       else if(a[m]==b[n])
       {
           co++;
           m--;
           n--;
       }
       else if(m>n)//if(lcs(a,b,m-1,n)>lcs(a,b,m,n-1))
       {
           m--;
       }
       else
       {
           n--;
       }
   }
   return co;
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

    cout<<lcs(a,b,a.size()-1,b.size()-1);
}
