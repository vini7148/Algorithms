#include <iostream>
#include <vector>

std::vector<int> a;

int minch(int m)
{
    int te=m;
    if(m==0)
        return 0;
    else
        return te;
}

int get_change(int m)
{
    int ans=0;
  for(int i=1;i<=m;i++)
  {
      for(int j=0;j<a.size();j++)
      {
          if(i>=a[j])
          {
              ans+=minch(i-a[j])+1;
              if(minch(i)>ans){}
                //minch(i)=ans;
          }
      }
  }
  return minch(m);
}

int main()
{
  a.push_back(1);
  a.push_back(3);
  a.push_back(4);

  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
