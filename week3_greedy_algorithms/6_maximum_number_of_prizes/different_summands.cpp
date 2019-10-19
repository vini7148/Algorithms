#include <iostream>
#include <vector>

using std::vector;

bool last(int i,int n)
{
    if((i*2)>=n)
        return true;
    else
        return false;
}

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int d=n;
  int co=0;
  if(n==1)
    summands.push_back(1);
  else
  {
      for(int i=1;i<n+1;i++)
      {
        if(last(i,n) && i<d-co)
        {
          summands.push_back(d-co);
          break;
        }

        if(i>d-co)
        {
          //summands[summands.size()-1]+=d-co;
          break;
        }

        summands.push_back(i);
        co+=i;
        n--;
    }

    if(summands[summands.size()-1]==summands[summands.size()-2])
        summands.pop_back();

    if(summands[summands.size()-1]<2)
        summands.pop_back();

    int su=0;

    for(int j=0;j<summands.size();j++)
        su+=summands[j];

    summands[summands.size()-1]+=d-su;

    if(summands[summands.size()-1]<2)
        summands.pop_back();
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
