#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pri(long long int n)
{
    vector<int> ans;
    while(n>=1)
    {
        ans.push_back(n);
        /*if(n%10!=0)
        {
            if (n % 3 == 0)
                n /= 3;
            else if (n % 2 == 0)
                n /= 2;
            else
                n = n - 1;
        }
        else*/ if((n-1)%3==0)
        {
            n=n-1;
        }
        else
        {
            if (n % 3 == 0)
                n /= 3;
            else if (n % 2 == 0)
                n /= 2;
            else
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
    vector<int> ans;
    ans=pri(n);
    cout<<ans.size()-1<<"\n";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}
