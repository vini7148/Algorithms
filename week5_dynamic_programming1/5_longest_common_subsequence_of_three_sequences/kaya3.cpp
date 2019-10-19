#include <iostream>
#include <vector>

using namespace std;

static int max(int a, int b)
{
    return (a > b)? a : b;
}

vector<int> lcsvec(vector<int> a, vector<int> b)
{
    int lengthA = a.size()+1,lengthB = b.size()+1,
        LCS = 0, i, j, maxLength, bd[101][101];

        maxLength = max(lengthA, lengthB);

        vector<int> cc(maxLength);

    for (i = 0; i < maxLength - 1; i++)
    {
        bd[i][0] = 0;
        bd[0][i] = 0;
    }

    for (i = 1; i < lengthA; i++)
    {
        for (j = 1; j < lengthB; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                cc.push_back(a[i-1]);
                bd[i][j] = bd[i-1][j-1] + 1;
                if(LCS < bd[i][j])
                {
                    LCS++;
                }
            }
            else
            {
                if (bd[i-1][j] > bd[i][j-1])
                {
                    bd[i][j] = bd[i-1][j];
                }
                else
                {
                    bd[i][j] = bd[i][j-1];
                }
            }
        }
    }
    if(LCS==cc.size())
        return cc;
}

int lcs(vector<int> a, vector<int> b)
{
    int lengthA = a.size()+1,lengthB = b.size()+1,
        LCS = 0, i, j, maxLength, bd[101][101];

        maxLength = max(lengthA, lengthB);

    for (i = 0; i < maxLength - 1; i++)
    {
        bd[i][0] = 0;
        bd[0][i] = 0;
    }

    for (i = 1; i < lengthA; i++)
    {
        for (j = 1; j < lengthB; j++)
        {
            if (a[i - 1] == b[j - 1])
            {

                bd[i][j] = bd[i-1][j-1] + 1;
                if(LCS < bd[i][j])
                {
                    LCS++;
                }
            }
            else
            {
                if (bd[i-1][j] > bd[i][j-1])
                {
                    bd[i][j] = bd[i-1][j];
                }
                else
                {
                    bd[i][j] = bd[i][j-1];
                }
            }
        }
    }

    return LCS;
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

    vector<int> cc(100000);
    cc=lcsvec(a,b);

    int o;
    cin>>o;
    vector<int> c(o);
    for(int i=0;i<o;i++)
        cin>>c[i];

    cout<<lcs(cc,c);
}
