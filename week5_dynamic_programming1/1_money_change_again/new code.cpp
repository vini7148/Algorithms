#include <iostream>
#include <vector>

using namespace std;

//int co=0;

int mich(int money,int co)
{
    if(money>=4 && money%4==0)
    {
        co+=money/4;
        return co;
    }

    else if(money>=4 && money%6==0 && money<10)
    {
        //cout<<mich(money-3)<<"\n";
        co+=money/3;
        return co;
    }

    else if(money>=4)
    {
        //cout<<mich(money-3)<<"\n";
        co++;
        return mich(money-4,co);
    }

    else if(money>=3 && money%3==0)
    {
        co+=money/3;
        return co;
    }

    else if(money>=3)
    {
        //cout<<mich(money-2)<<"\n";
        co++;
        return mich(money-3,co);
    }

    else
    {
        co+=money;
        return co;
    }
}

/*int cha(int money,vector<int> a)
{
    //unsigned long int mi=-1;
    for(int i=0;i<3;i++)
        if(money>=a[i])
            return cha(money-a[i]+1,a);
    return money;
}*/

int main()
{
    /*vector<int> a(3);
    a.push_back(4);
    a.push_back(3);
    a.push_back(1);*/
    int money;
    cin>>money;
    cout<<mich(money,0);//<<"\n"<<co;
}
