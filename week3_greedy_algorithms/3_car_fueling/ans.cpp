#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops,int n) {
    int num=0,curr=0;
    int fl=0;
    while(curr<=n)
    {
        int last=curr;
        fl=0;

        while(curr<=n && stops[curr+1]-stops[last]<=tank)
        {
            curr++;
        }

        if(curr==last)
        {
            fl=1;
            break;
        }

        if(curr<=n)
            num++;
    }
    if(fl!=1)
        return num;
    else
        return -1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    stops[0]=0;
    for (size_t i = 1; i <= n; ++i)
        cin >> stops[i];
    stops[n+1]=d;
    cout << compute_min_refills(d, m, stops,n+1) << "\n";

    return 0;
}
