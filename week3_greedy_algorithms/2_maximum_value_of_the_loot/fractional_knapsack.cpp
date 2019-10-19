#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(double capacity, vector<double> weights, vector<double> values, int n)
{
  double value = 0.0;
  while(capacity && n)
  {
      double maxi=0;
      int j=-1;
      for(int i=0;i<n;i++)
      {
          //if(weights[i]!=0)
            if(maxi<(values[i]/weights[i]))
            {
                maxi=values[i]/weights[i];
                j=i;
            }
      }

      if(capacity<weights[j])
      {
          value+=capacity*values[j]/weights[j];
          capacity-=capacity;
      }
      else
      {
          value+=values[j];
          capacity-=weights[j];
          //weights[j]=0;
      }

      n--;
      for(int i=j;i<n;i++)
      {
          weights[i]=weights[i+1];
          values[i]=values[i+1];
      }
  }
  return value;
}

int main()
{
  int n;
  double capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++)
    std::cin >> values[i] >> weights[i];

  double optimal_value = get_optimal_value(capacity, weights, values, n);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
