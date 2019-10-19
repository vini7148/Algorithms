#include <iostream>
#include <vector>

using namespace std;

static int max(int a, int b)
{
    return (a > b)? a : b;
}

int lcs(string a,string b,int n,int m)
{
    int lengthA = n+1,lengthB = m+1,LCS = 0, i, j, maxLength, bd[101][101];

        maxLength = max(lengthA, lengthB);

    int ans=0,I=-1,J=-1;

    for (i = 0; i < maxLength - 1; i++)
    {
        bd[i][0] = i;
        bd[0][i] = i;
    }

    for (i = 1; i < lengthA; i++)
    {
        for (j = 1; j < lengthB; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                bd[i][j] = bd[i-1][j-1];
                if(LCS < bd[i][j])
                {
                    LCS++;
                    I=i;
                    J=j;
                }
            }
            else
            {
                if (bd[i-1][j] < bd[i][j-1])
                {
                    bd[i][j] = bd[i-1][j]+1;
                }
                else
                {
                    bd[i][j] = bd[i][j-1]+1;
                }
            }

        }
    }

    return bd[I][J];
}

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;

    cout << lcs( str1 , str2 , str1.length(), str2.length());

}
