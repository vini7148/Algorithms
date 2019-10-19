#include <iostream>
#include <vector>
#include <list>
#include <climits>

void primitive_calculator(long long int n)
{
        std::vector<int> mi(n+1,INT_MAX);
        std::list<int>* pa=new std::list<int>[n+1];
        mi[0]=0;
        mi[1]=0;
        pa[0].push_back(0);
        pa[1].push_back(1);
        for(int i=2;i<=n;i++)
        {
            if(i%3==0)
            {
                if(mi[i/3] < mi[i])
                {
                        mi[i]=mi[i/3]+1;
                        pa[i]=pa[i/3];
                        pa[i].push_back(i);
                }
            }
            if(i%2==0)
            {
                if( mi[i/2] < mi[i])
                {
                        mi[i]=mi[i/2]+1;
                        pa[i]=pa[i/2];
                        pa[i].push_back(i);
                }
            }
            if( mi[i-1] < mi[i])
            {
                mi[i]=mi[i-1]+1;
                pa[i]=pa[i-1];
                pa[i].push_back(i);
            }
    }
    std::cout<<mi[n]<<"\n"<<"1 ";
    while(!pa[n].empty())
    {
            pa[n].pop_front();
            long long int x=pa[n].front();
            if(x!=0)
                std::cout<<pa[n].front()<<" ";
    }
}

int main()
{
    long long int n;
    //n=1000000;
    std::cin>>n;
    primitive_calculator(n);
    return 0;
}
