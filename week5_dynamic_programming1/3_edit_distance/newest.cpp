#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using std::vector;
using std::cin;
using std::cout;
using std::string;

inline int min(int x, int y, int z)
{
    if (x < y)
        return x < z ? x : z;
    else
        return y < z ? y : z;
}

int edit_distance(string A,string B)
{
    int NA = A.size();
    int NB = B.size();

    vector< vector<int> > M(NA + 1, vector<int>(NB + 1));

    for (int a = 0; a <= NA; ++a)
        M[a][0] = a;

    for (int b = 0; b <= NB; ++b)
        M[0][b] = b;

    for (int a = 1; a <= NA; ++a)
        for (int b = 1; b <= NB; ++b)
        {
            int x = M[a-1][b] + 1;
            int y = M[a][b-1] + 1;
            int z = M[a-1][b-1] + ((A[a-1] == B[b-1]) ? 0 : 1);
            M[a][b] = min(x,y,z);
        }

    return M[A.size()][B.size()];
}

int main()
{
    string str1;
    string str2;
    cin >> str1 >> str2;

    cout << edit_distance( str1 , str2 );

}
