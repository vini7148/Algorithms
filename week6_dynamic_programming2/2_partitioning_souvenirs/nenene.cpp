#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ma(int W,vector<int> a,int n)
{
    vector< vector<int> > va(W+1,vector<int>(n+1));

    for(int w=0;w<=W;w++)
        va[w][0]=0;
    for(int j=0;j<=n;j++)
        va[0][j]=0;

    //sort(a.begin(),a.end());

    int vv=0;

    for( int i = 1; i <= n; i++ )
    {
        for( int w = 1; w <= W; w++ )
        {
            va[w][i] = va[w][i - 1];
            if( a[i-1] <= w )
            {
                vv = va[w - a[i-1]][i - 1] + a[i-1];
                if( va[w][i] < vv )
                    va[w][i] = vv;
            }
        }
    }

    /*cout<<"\n";
    for(int w=0;w<=W;w++)
    {
        for(int i=0;i<=n;i++)
        {
            cout<<va[w][i]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";*/

    return va[W][n];
}

int ch(int W,vector<int> a,int n)
{
    if(W==ma(W,a,n))
    {
        reverse(a.begin(),a.end());
        if(W==ma(W,a,n))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int main()
{
    int su=0,n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        su+=a[i];
    }
    if(su%3==0)
    {
        cout<<ch(su/3,a,n);
    }
    else
        cout<<0;
}
